#ifndef IGAMEMANAGER_HPP_
# define IGAMEMANAGER_HPP_

# include <string>
# include "IGameMap.hpp"
# include "IGame.hpp"

class IJudge;

class IGameManager
{
public:
  virtual ~IGameManager() {}

public:
  virtual IJudge *		getJudge() const = 0;
  virtual IGame *		createGame(IGame::mode gameMode) = 0;
  virtual IGame *		getGame() const  = 0;
  virtual void			start() const = 0;
  virtual void	didClickCase(unsigned int x, unsigned y) = 0;
  virtual void		removeGame() = 0;
};

#endif  /* !IGAMEMANAGER_HPP_ */
