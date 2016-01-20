#ifndef IGUI_H_
# define IGUI_H_

#include "IGameMap.hpp"
#include <string>

class IGui
{
public:
  virtual void setButtonColor(int x, int y, Case::caseContent) = 0;
  virtual void setFull(int x, int y, bool) = 0;
  virtual void setWin(int Player) = 0;
  virtual void start() = 0;
  virtual void changeTurn() = 0;
  virtual void showError(std::string const&) = 0;
  virtual double getAITimeout() const = 0;
protected:

};

#endif /* !IGUI_H_ */
