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
  void setButtoncolor(int x, int y, IGameMap::caseContent);
  void run();
protected:
  QApplication* _app;
  MainWindow* _win;
  IGameManager* _gm;
};

#endif /* !GUI_H_ */
