#ifndef IGAMEMANAGER_HPP_
# define IGAMEMANAGER_HPP_

# include <string>
# include "IGameMap.hpp"

class IGameManager
{
public:
  enum		mode
    {PVP, PVE, EVE};

public:
  virtual ~IGameManager() {}

protected:
  virtual bool			initJudge();
  virtual void			initPlayer();

public:
  virtual IGame *		createGame() = 0;
  virtual void			changeMode(mode) = 0;
  virtual IGameMap::caseContent didClickCase(unsigned int x, unsigned y) = 0;
};

#endif  /* !IGAMEMANAGER_HPP_ */
