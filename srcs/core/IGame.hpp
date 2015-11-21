#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "IGameMap.hpp"
#include "IPlayer.hpp"

class IGame
{
public:
  virtual ~IGame() {}

public:
  virtual IGameMap *	getMap() const = 0;
  virtual IPlayer *	getPlayer() const = 0;
  virtual bool		nextAction() const = 0;
  virtual bool		isFinished() const = 0;
  virtual IPlayer *	getWinner() const = 0;
};

#endif /* !IGAME_HPP_ */
