#ifndef IGUI_H_
# define IGUI_H_

#include "../srcs/core/IGameMap.hpp"
#include "../srcs/core/IGameManager.hpp"

class IGui
{
public:
  void setButtonColor(int x, int y, IGameMap::caseContent);
  void run();
protected:

};

#endif /* !IGUI_H_ */
