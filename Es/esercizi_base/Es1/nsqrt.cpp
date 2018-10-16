#include "nsqrt.h"
#include <math.h>
double nsqrt(double x, double epsilon) {
  double s0 = x / 2;
  double sk = s0;
  do {
    sk = (pow(sk, 2) + x) / (2 * sk);
  }
  while(fabs((sk*sk) - x ) > epsilon);
  return sk;
}
