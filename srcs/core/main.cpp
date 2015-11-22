#include "mainwindow.h"
#include "Gui.hpp"
#include "../srcs/core/GameManager.hpp"
#include <QApplication>

int main(int argc, char** argv)
{
  IGameManager* gm = new GameManager(argc, argv);

  gm->start();
  return 0;
}
