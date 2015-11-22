#ifndef GAME_HPP_
# define GAME_HPP_

#include "IGame.hpp"
#include "IGameMap.hpp"
#include "IGui.hpp"
#include "IPlayer.hpp"

class Game : public IGame
{
public:
  Game(mode gameMode, IGui*);
  virtual ~Game();

private:
  IGui *	_gui;
  IGameMap *	_map;
  mode		_mode;
  IPlayer * 	_players[2];
  IPlayer *	_winner;
  bool		_finish;
  bool		_turn;

public:
  virtual void		initPlayer();
  virtual IPlayer *	getPlayer(unsigned int id) const;
  virtual IPlayer *	getActivePlayer() const;

  virtual IGui *	getGui() const;
  virtual IGameMap *	getMap() const;
  virtual mode		getMode() const;
  virtual void		changeMode(mode newMode);

  virtual void		setCase(unsigned int x, unsigned int y, IGameMap::caseContent color);

  virtual void		playTurn(unsigned int x, unsigned int y);
  virtual void		endTurn();

  virtual void		setWinner();
  virtual void		setFinish();

  virtual bool		isFinished() const;
  virtual IPlayer *	getWinner() const;
};

#endif /* !GAME_HPP_ */
