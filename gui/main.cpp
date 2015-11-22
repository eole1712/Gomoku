#include "mainwindow.h"
#include "Gui.hpp"
#include "../srcs/core/GameManager.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
  IGui* gui;
  IGameManager* gm;

  gm = new GameManager();
  gui = new Gui(gm, 0, nullptr);
  /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
  //gui->run();
}
