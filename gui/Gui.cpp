#include "Gui.hpp"

Gui::Gui(IGameManager* gm, int argc, char** argv)
  :IGui(), _app(new QApplication(argc, argv)), _win(new MainWindow(0, gm)), _gm(gm)
{
  ;
  if (_win && _app) {
    _win->show();
    _app->exec();
  }
}

Gui::~Gui()
{
  delete _app;
  delete _win;
}

void Gui::setButtoncolor(int x, int y, IGameMap::caseContent col)
{
  _win->setButtonColor(x, y, col);
}
