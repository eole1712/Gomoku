#include "Gui.hpp"
#include <iostream>
Gui::Gui(IGameManager* gm, int &argc, char** argv)
  :IGui(), _app(new QApplication(argc, argv)), _win(new MainWindow(0, gm)), _gm(gm)
{
}

Gui::~Gui()
{
}

void	Gui::start()
{
  if (_win && _app) {
    _win->show();
    _app->exec();
    delete _win;
    delete _app;
  }
}

void Gui::setButtonColor(int x, int y, Case::caseContent col)
{
  _win->setButtonColor(x, y, col);
}

void Gui::setPosable(int x, int y, bool pos, bool color)
{
    _win->setPosable(x, y, pos, color);
}

void Gui::setFull(int x, int y, bool isFull)
{
    _win->setFull(x, y, isFull);
}

void Gui::setWin(int Player)
{
    _win->setWin(Player);
}

void Gui::changeTurn()
{
    _win->changeTurn();
}

void Gui::showError(const std::string & errorText)
{
    _win->showError(errorText);
}

double Gui::getAITimeout() const
{
    return _win->getAITimeout();
}
