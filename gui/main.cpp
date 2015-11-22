#include "mainwindow.h"
#include "Gui.hpp"
#include "../srcs/core/GameManager.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
  IGui* gui;
  IGameManager* gm;

  gm = new GameManager();
  gui = new Gui(gm, argc, argv);
  /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
