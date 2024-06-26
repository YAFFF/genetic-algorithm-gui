#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "functions.h"
#include "geneticalgorithm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connecting();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::connecting() {
  connect(ui->getResultButton, SIGNAL(clicked()), this,
          SLOT(getResultButtonSlot()));
}

void MainWindow::getResultButtonSlot() {
  double (*currentFunction)(double, double);
  if (ui->firstFormulaRadioButton->isChecked()) {
    currentFunction = function1;
  } else if (ui->secondFormulaRadioButton->isChecked()) {
    currentFunction = function2;
  } else if (ui->thirdFormulaRadioButton->isChecked()) {
    currentFunction = function3;
  } else if (ui->fourthFormulaRadioButton->isChecked()) {
    currentFunction = function4;
  } else if (ui->fifthFormulaRadioButton->isChecked()) {
    currentFunction = function5;
  } else {
    return;
  }
  GeneticAlgorithm geneticAlgorithm(currentFunction);
  ui->listOfIndividualsTextBrowser->clear();
  if (!geneticAlgorithm.isResult()) {
    ui->resultLabel->setText("on_extremes");
    return;
  }
  ui->resultLabel->setText(QString::number(geneticAlgorithm.getResult()));
  for (auto i : geneticAlgorithm.getBestIndividualsList()) {
    ui->listOfIndividualsTextBrowser->append(QString::fromStdString(i));
  }
}
