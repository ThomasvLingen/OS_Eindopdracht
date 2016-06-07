#ifndef COEFFICIENTS_H
#define COEFFICIENTS_H

#include <math.h>


namespace ATE_Util {

  enum class CoefficientType{bass, treble};

  class Coefficients{
  public:
      Coefficients(int intensity, CoefficientType type);
      double b0, b1, b2;
      double a1, a2;

      void bassCalc  (int intensity);
      void trebleCalc(int intensity);
  };

}

#endif // COEFFICIENTS_H
