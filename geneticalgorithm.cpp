#include "geneticalgorithm.h"
#include "individual.h"
#include <string>
#include <vector>

GeneticAlgorithm::GeneticAlgorithm(double (*functionZ)(double, double))
    : functionZ(functionZ) {
  valumeMinMax = false;
  isResultExist = true;
  std::uniform_real_distribution<double> dist(-16, 16);
  for (int i = 0; i < 100; i++) {
    double x = dist(rd), y = dist(rd);
    population.emplace_back(x, y, functionZ(x, y));
  }
  for (int i = 0; i < 100; i++) {
    fitness();
    crossOver();
    mutation();
    double rs = result(valumeMinMax);
    std::string bestIndividual =
        std::to_string(i + 1) + ": " + findBestIndividual(rs) + "\n";

    bestIndividualsList.push_back(bestIndividual);
    if (result(valumeMinMax) < -100) {
      valumeMinMax = true;
      i = 0;
    } else if (result(valumeMinMax) > 100) {
      isResultExist = false;
      break;
    }
  }
}

void GeneticAlgorithm::fitness() {
  geneticBank.clear();
  std::vector<Individual> a;
  for (int i = 0; i < 100; i += 25) {
    a.push_back(population[cycle(i, valumeMinMax)]);
  }
  for (int i = 0; i < 25; i++) {
    for (auto j : a) {
      geneticBank.push_back(j);
    }
  }
}

void GeneticAlgorithm::crossOver() {
  std::uniform_int_distribution<int> dist(0, 99);
  population.clear();
  for (int i = 0; i < 100; i++) {
    double x = geneticBank[i].getX(), y = geneticBank[dist(rd)].getY();
    population.emplace_back(x, y, functionZ(x, y));
  }
}

void GeneticAlgorithm::mutation() {
  std::uniform_real_distribution<double> dist1(-16, 16);
  std::uniform_int_distribution<int> dist2(0, 1);
  for (int i = 0; i < 100; i++) {
    if (dist2(rd)) {
      if (dist2(rd)) {
        double x = population[i].getX(), y = dist1(rd);
        population[i] = Individual(x, y, functionZ(x, y));
      } else {
        double y = population[i].getY(), x = dist1(rd);
        population[i] = Individual(x, y, functionZ(x, y));
      }
    }
  }
}

int GeneticAlgorithm::cycle(int a, bool b) {
  double m = population[a].getZ();
  int index = a;
  for (int i = a + 1; i < a + 25; i++) {
    if (b ? m < population[i].getZ() : m > population[i].getZ()) {
      m = population[i].getZ();
      index = i;
    }
  }
  return index;
}

double GeneticAlgorithm::result(bool b) {
  double m = population[0].getZ();
  for (auto i : population) {
    if (b ? m < i.getZ() : m > i.getZ()) {
      m = i.getZ();
    }
  }
  return m;
}

std::string GeneticAlgorithm::findBestIndividual(double z) {
  for (auto i : population) {
    if (i.getZ() == z) {
      return std::to_string(i.getX()) + "; " + std::to_string(i.getY()) + "; " +
             std::to_string(i.getZ());
    }
  }
  return "";
}

double GeneticAlgorithm::getResult() { return result(valumeMinMax); }

bool GeneticAlgorithm::isResult() { return isResultExist; }

std::vector<std::string> GeneticAlgorithm::getBestIndividualsList() {
  return bestIndividualsList;
}
