#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "IGameMap.hpp"
#include "IPlayer.hpp"

class IGame
{
public:
  virtual ~IGame() {}


public:
  enum		mode
    {PVP, PVE, EVE};

public:
  virtual void		initPlayer() = 0;
  virtual Player *	getPlayer() const = 0;
  virtual Player *	getActivePlayer() const = 0;

  virtual GameMap *	getMap() const = 0;
  virtual mode		getMode() const = 0;
  virtual mode		getMode() const = 0;
  virtual void		changeMode(mode newMode) = 0;

  virtual IGameMap::caseContent	play(Judge * judge, unsigned int x, unsigned int y) = 0;

  virtual bool		isFinished() const = 0;
  virtual IPlayer *	getWinner() const = 0;
};

#endif /* !IGAME_HPP_ */
