#ifndef IGAMEMANAGER_HPP_
# define IGAMEMANAGER_HPP_

# include <string>
# include "IGameMap.hpp"
# include "IPlayer.hpp"
# include "IGame.hpp"
# include "IJudge.hpp"

class IGameManager
{
public:
  virtual ~IGameManager() {}

public:
  virtual IJudge *		getJudge() const = 0;
  virtual IGame *		createGame(IGame::mode gameMode) = 0;
  virtual IGame *		getGame() const  = 0;
  virtual IGameMap::caseContent	didClickCase(unsigned int x, unsigned y) = 0;
};

#endif  /* !IGAMEMANAGER_HPP_ */
