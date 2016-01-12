#include "mainwindow.h"
#include "Gui.hpp"
#include "GameManager.hpp"
#include <QApplication>

int main(int ac, char **av)
{
  IGameManager* gm = new GameManager(ac, av);

  gm->start();
  return 0;
}
