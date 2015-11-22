#include "Gui.hpp"

Gui::Gui(IGameManager* gm, int argc, char** argv)
  :IGui(), _app(argc, argv), _win(nullptr, gm), _gm(gm)
{
  ;
}

Gui::~Gui()
{
  ;
}

void Gui::setButtoncolor(int x, int y, IGameMap::caseContent col)
{
  _win.setButtonColor(x, y, col);
}
