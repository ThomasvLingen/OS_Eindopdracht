#include "coefficients.hpp"


namespace ATE_Util {

  Coefficients::Coefficients(int intensity, CoefficientType type){
      switch(type){
          case CoefficientType::bass:
              this->bassCalc(intensity);
              break;
          case CoefficientType::treble:
              this->trebleCalc(intensity);
              break;
      }
  }

  void Coefficients::bassCalc(int intensity){
      double frequency = 330;
      double qFactor = 0.5;
      double gain = intensity;
      double sampleRate = 44100;
      double pi=4.0*atan(1);

      double a=pow(10.0, gain/40);
      double w0=2*pi*frequency/sampleRate;
      double alpha=sin(w0)/(2.0*qFactor);
      double a0=(a+1)+(a-1)*cos(w0)+2.0*sqrt(a)*alpha;

      this->a1=-(-2.0*((a-1)+(a+1)*cos(w0)))/a0;
      this->a2=-((a+1)+(a-1)*cos(w0)-2.0*sqrt(a)*alpha)/a0;
      this->b0=(a*((a+1)-(a-1)*cos(w0)+2.0*sqrt(a)*alpha))/a0;
      this->b1=(2*a*((a-1)-(a+1)*cos(w0)))/a0;
      this->b2=(a*((a+1)-(a-1)*cos(w0)-2.0*sqrt(a)*alpha))/a0;
  }

  void Coefficients::trebleCalc(int intensity){
      double frequency = 3300;
      double qFactor = 0.5;
      double gain = intensity;
      double sampleRate = 44100;
      double pi=4.0*atan(1);

      double a=pow(10.0, gain/40);
      double w0=2*pi*frequency/sampleRate;
      double alpha=sin(w0)/(2.0*qFactor);

      double a0=(a+1)-(a-1)*cos(w0)+2.0*sqrt(a)*alpha;

      this->a1=-(2.0*((a-1)-(a+1)*cos(w0)))/a0;
      this->a2=-((a+1)-(a-1)*cos(w0)-2.0*sqrt(a)*alpha)/a0;
      this->b0=(a*((a+1)+(a-1)*cos(w0)+2.0*sqrt(a)*alpha))/a0;
      this->b1=(-2.0*a*((a-1)+(a+1)*cos(w0)))/a0;
      this->b2=(a*((a+1)+(a-1)*cos(w0)-2.0*sqrt(a)*alpha))/a0;
  }

}
