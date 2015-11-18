#ifndef GAME_HPP_
# define GAME_HPP_

#include "IGame.hpp"

class Game
{
public:
  Game();
  virtual ~Game();

private:
  GameMap	_map;
  IPlayer 	_players[2];
  IPlayer *	_winner;
  bool		_finish;
  bool		_turn;

public:
  IGameMap *	getMap() const;
  IPlayer *	getPlayer() const;
  bool		nextAction() const;
  bool		isFinished() const;
  bool		getTurn() const;
  void		setTurn(bool);
  IPlayer *	getWinner() const;
};

#endif /* !GAME_HPP_ */
