#include "mainwindow.h"
#include "Gui.hpp"
#include "../srcs/core/GameManager.hpp"
#include <QApplication>

int main()
{
  IGameManager* gm;

   gm = new GameManager();
   (void)gm;
   /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
  //gui->run();
  return 0;
}
