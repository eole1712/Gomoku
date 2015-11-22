#ifndef GUI_H_
# define GUI_H_

#include "IGui.hpp"
#include "mainwindow.h"
#include <QApplication>

class Gui : public IGui
{
public:
  Gui(IGameManager*, int argc, char** argv);
  virtual ~Gui();

  virtual void start();
  virtual void setWin(int Player);
  virtual void changeTurn();
  virtual void setButtonColor(int x, int y, IGameMap::caseContent);
protected:
  QApplication* _app;
  MainWindow* _win;
  IGameManager* _gm;
};

#endif /* !GUI_H_ */
