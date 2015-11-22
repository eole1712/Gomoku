#include "mainwindow.h"
#include "Gui.hpp"
#include "../srcs/core/GameManager.hpp"
#include <QApplication>

int main()
{
  IGameManager* gm = new GameManager();

  gm.start();
  /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
  //gui->run();
  return 0;
}
