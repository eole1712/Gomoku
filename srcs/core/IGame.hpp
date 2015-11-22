#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "IGameMap.hpp"
#include "IPlayer.hpp"

class IGui;

class IGame
{
public:
  virtual ~IGame() {}

public:
  enum		mode
    {PVP, PVE, EVE};

public:
  virtual void		initPlayer() = 0;
  virtual IPlayer *	getPlayer(unsigned int id) const = 0;
  virtual IPlayer *	getActivePlayer() const = 0;

  virtual IGui *	getGui() const = 0;
  virtual IGameMap *	getMap() const = 0;
  virtual mode		getMode() const = 0;
  virtual void		changeMode(mode newMode) = 0;

  virtual void    setCase(unsigned int x, unsigned int y, IGameMap::caseContent color) = 0;

  virtual void		playTurn(unsigned int x, unsigned int y) = 0;
  virtual void		endTurn() = 0;

  virtual void		setWinner() = 0;
  virtual void		setFinish() = 0;

  virtual bool		isFinished() const = 0;
  virtual IPlayer *	getWinner() const = 0;
};

#endif /* !IGAME_HPP_ */
