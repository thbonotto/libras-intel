#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ostream>

using namespace std;

namespace Ui {



class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
  void clickMenuButton();
  void on_start_clicked();
  void letra_reconhecida(char l);
};

#endif // MAINWINDOW_H
