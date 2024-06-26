#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/qtmetamacros.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  Ui::MainWindow *ui;

  void connecting();
  void calculate(int);

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void getResultButtonSlot();
};
#endif // MAINWINDOW_H
