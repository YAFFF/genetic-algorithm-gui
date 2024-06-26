#include "functions.h"

#include <cmath>

double function1(double x, double y) {
  return (3 * pow(x, 2) + x * y + 2 * pow(y, 2) - x - 4 * y);
}

double function2(double x, double y) {
  return pow(y, 2) + 2 * x * y - 4 * x - 2 * y - 3;
}

double function3(double x, double y) {
  return -2 * pow(y, 2) - x - 14 * y + y * sqrt(x);
}

double function4(double x, double y) {
  return exp(x + y) * (pow(x, 2) - 2 * pow(y, 2));
}

double function5(double x, double y) {
  return 4 + pow((pow(x, 2) + pow(y, 2)), 2 / 3.);
}
