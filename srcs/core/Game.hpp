#ifndef GAME_HPP_
# define GAME_HPP_

#include "IGame.hpp"
#include "GameMap.hpp"

class Game : IGame
{
public:
  Game();
  virtual ~Game();

private:
  GameMap	_map;
  mode		_mode;
  Player 	_players[2];
  Player *	_winner;
  bool		_finish;
  bool		_turn;

public:
  void		initPlayer();
  Player *	getPlayer() const;
  Player *	getActivePlayer() const;

  GameMap *	getMap() const;
  mode		getMode() const;
  mode		getMode() const;
  void		changeMode(mode newMode);

  IGameMap::caseContent	play(Judge * judge, unsigned int x, unsigned int y);

  bool		isFinished() const;
  IPlayer *	getWinner() const;
};

#endif /* !GAME_HPP_ */
