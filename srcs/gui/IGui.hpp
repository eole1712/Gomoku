#ifndef IGUI_H_
# define IGUI_H_

#include "IGameMap.hpp"

class IGui
{
public:
  virtual void setButtonColor(int x, int y, IGameMap::caseContent) = 0;
  virtual void start() = 0;
protected:

};

#endif /* !IGUI_H_ */
