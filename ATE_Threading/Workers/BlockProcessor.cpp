//
// Created by mafn on 6/5/16.
//

#include "BlockProcessor.hpp"


namespace ATE_Threading {

  BlockProcessor::BlockProcessor(ThreadManager &thread_manager, BlockQueue &target, Coefficients &bass_coeff, Coefficients &treble_coeff)
          : ThreadWorker(thread_manager),
            target(target),
            bass_coeff(bass_coeff),
            treble_coeff(treble_coeff)
  {
      if (DEBUG) {
          cout << "Spawning new consumer thread" << endl;
      }

      this->run();
  }

  BlockProcessor::~BlockProcessor() {

  }

  void BlockProcessor::thread_target() {
      while (!target.is_processed()) {
          Block* to_process = target.get_next_block_to_process();

          if (to_process) {
              this->process_block(to_process);
          }
      }
  }

  void BlockProcessor::process_block(Block *to_process) {
      if (DEBUG) {
          cout << "[WORKER] Processing " << to_process->ID << endl;
      }

      this->apply_coefficients(to_process, this->bass_coeff);
      to_process->advance();
      this->apply_coefficients(to_process, this->treble_coeff);
      to_process->advance();

      to_process->status = ATE_BlockQueue::Block_status::processed;
  }

  void BlockProcessor::apply_coefficients(Block *target, Coefficients &to_apply) {
      // We start with sample 2 because the filter needs the previous 2 samples
      for (int sample_index = 2; sample_index < sizeof(target->samples) / sizeof(short); sample_index++) {
          double b0 = target->samples[sample_index] * to_apply.b0;
          double b1 = target->samples[sample_index-1] * to_apply.b1;
          double b2 = target->samples[sample_index-2] * to_apply.b2;
          double a1 = target->samples[sample_index-1] * to_apply.a1;
          double a2 = target->samples[sample_index-2] * to_apply.a2;

          target->samples[sample_index] = (short) b0+b1+b2+a1+a2;
      }
  }

}