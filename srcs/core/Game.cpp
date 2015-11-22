#include <string>
#include "Human.hpp"
#include "AI.hpp"
#include "Game.hpp"

Game::Game(mode gameMode)
  : _map(), _mode(gameMode), _winner(NULL), _finish(false), _turn(false)
{
  initPlayer();
}

Game::~Game()
{}

void		Game::initPlayer()
{
  if (_mode == PVE)
    {
      _players[0] = new Human();
      _players[1] = new AI();
    }
  if (_mode == PVP)
    {
      _players[0] = new Human();
      _players[1] = new Human();
    }
}

IPlayer *	Game::getPlayer(unsigned int id) const
{
  if (id > 1)
    return NULL;
  return _players[id];
}

IPlayer *	Game::getActivePlayer() const
{
  return _players[_turn];
}

IGameMap *	Game::getMap() const
{
  return _map;
}


IGame::mode		Game::getMode() const
{
  return _mode;
}

void		Game::setCase(unsigned int x, unsigned int y, IGameMap::caseContent color)
{
	getMap->setCase(x, y, color);
 	getGameManager->getGui->setCase(x, y, color);
}

void		Game::changeMode(IGame::mode newMode)
{
  if (_mode == newMode)
    return ;
  _mode = newMode;
  if (_mode != EVE)
    _players[0] = new Human(_players[0]);
  else
    _players[0] = new AI(_players[0]);

  if (_mode != PVP)
    _players[1] = new AI(_players[1]);
  else
    _players[1] = new Human(_players[1]);
}

void		Game::playTurn(unsigned int x, unsigned int y)
{
  _players[_turn]->setPosition(x, y);
  // if ai ? player[_turn].play(_game.getMap());
}

void		Game::endTurn()
{
  _turn = !_turn;
}


bool		Game::isFinished() const
{
  return _finish;
}

IPlayer *	Game::getWinner() const
{
  return _winner;
}
