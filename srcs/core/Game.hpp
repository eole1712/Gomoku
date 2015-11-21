#ifndef GAME_HPP_
# define GAME_HPP_

#include "IGame.hpp"
#include "IGameMap.hpp"
#include "IPlayer.hpp"

class Game : public IGame
{
public:
  Game(mode gameMode);
  virtual ~Game();

private:
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

  virtual IGameMap *	getMap() const;
  virtual mode		getMode() const;
  virtual void		changeMode(mode newMode);

  virtual void		playTurn(unsigned int x, unsigned int y);
  virtual void		endTurn();

  virtual bool		isFinished() const;
  virtual IPlayer *	getWinner() const;
};

#endif /* !GAME_HPP_ */
