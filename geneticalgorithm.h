#ifndef GENETICALGORITHMGUI_GENETICALGORITHM_H
#define GENETICALGORITHMGUI_GENETICALGORITHM_H

#include "individual.h"
#include <random>
#include <string>
#include <vector>

class GeneticAlgorithm {
private:
  std::vector<Individual> population, geneticBank;
  std::vector<std::string> bestIndividualsList;
  bool valumeMinMax, isResultExist;
  std::random_device rd;
  double (*functionZ)(double, double);

  void fitness();
  void crossOver();
  void mutation();
  int cycle(int, bool);
  double result(bool);
  std::string findBestIndividual(double);

public:
  GeneticAlgorithm();
  GeneticAlgorithm(double (*)(double, double));
  double getResult();
  bool isResult();
  std::vector<std::string> getBestIndividualsList();
};

#endif // !GENETICALGORITHMGUI_GENETICALGORITHM_H
