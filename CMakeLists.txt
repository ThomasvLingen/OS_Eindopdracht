cmake_minimum_required(VERSION 2.8)
project(mafn_ate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )

include_directories(${CMAKE_SOURCE_DIR})

set(
    SOURCE_FILES
    main.cpp
    OS_namespaces.h
    config.hpp
    ATE_BlockQueue/block.cpp                   ATE_BlockQueue/block.hpp
    ATE_BlockQueue/blockqueue.cpp              ATE_BlockQueue/blockqueue.hpp
    ATE_Threading/Workers/blockqueuefiller.cpp ATE_Threading/Workers/blockqueuefiller.hpp
    ATE_Threading/Workers/BlockProcessor.cpp   ATE_Threading/Workers/BlockProcessor.hpp
    ATE_Threading/ThreadManager.cpp            ATE_Threading/ThreadManager.hpp
    ATE_Threading/ThreadWorker.cpp             ATE_Threading/ThreadWorker.hpp
    ATE_Util/coefficients.cpp                  ATE_Util/coefficients.hpp
    ATE_Util/options.cpp                       ATE_Util/options.hpp
    ATE_Util/wait.hpp
)

find_package (Threads)
add_executable(mafn_ate ${SOURCE_FILES})
target_link_libraries (mafn_ate ${CMAKE_THREAD_LIBS_INIT})