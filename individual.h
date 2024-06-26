#ifndef GENETICALGORITHM_INDIVIDUAL_H
#define GENETICALGORITHM_INDIVIDUAL_H

class Individual {
private:
  double x, y, z;

public:
  Individual(double, double, double);
  double getX();
  double getY();
  double getZ();
};

#endif // !GENETICALGORITHM_INDIVIDUAL_H
