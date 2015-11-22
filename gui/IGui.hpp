#ifndef IGUI_H_
# define IGUI_H_

#include "../srcs/core/IGameMap.hpp"
#include "../srcs/core/IGameManager.hpp"

class IGui
{
public:
  virtual void setButtonColor(int x, int y, IGameMap::caseContent) = 0;
  virtual void start() = 0;
protected:

};

#endif /* !IGUI_H_ */
