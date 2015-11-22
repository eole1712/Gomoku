#include "Gui.hpp"
#include <iostream>
Gui::Gui(IGameManager* gm, int argc, char** argv)
  :IGui(), _app(new QApplication(argc, argv)), _win(new MainWindow(0, gm)), _gm(gm)
{
}

Gui::~Gui()
{
}

void	Gui::start()
{
  if (_win && _app) {
    std::cout << std::endl;
    _win->show();
    _app->exec();
    delete _win;
    delete _app;
  }
}

void Gui::setButtonColor(int x, int y, IGameMap::caseContent col)
{
  _win->setButtonColor(x, y, col);
}

void Gui::setWin(int Player)
{
    _win->setWin(Player);
}

void Gui::changeTurn()
{
    _win->changeTurn();
}
