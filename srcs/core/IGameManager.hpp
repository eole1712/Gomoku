#ifndef IGAMEMANAGER_HPP_
# define IGAMEMANAGER_HPP_

# include <string>
# include "GameMap.hpp"
# include "Player.hpp"
# include "Game.hpp"
# include "Judge.hpp"

class IGameManager
{
public:
  virtual ~IGameManager() {}


public:
  virtual bool			initJudge();
  virtual Judge *		getJudge() const = 0;
  virtual Game *		createGame() = 0;
  virtual Game *		getGame() const  = 0;
 virtual IGameMap::caseContent	didClickCase(unsigned int x, unsigned y) const = 0;
};

#endif  /* !IGAMEMANAGER_HPP_ */
