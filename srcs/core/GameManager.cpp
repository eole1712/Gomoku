#include "GameManager.hpp"

GameManager::GameManager(mode gameMode)
  : _mode(gameMode), _game(createGame())
{
  initJudge();
  initPlayer();
}

GameManager::~GameManager()
{
  delete _players[0];
  delete _players[1];
  delete _game;
}

bool			GameManager::initJudge();
{
  // ne pas modifier l'ordre des régles !
  _judge.addRule(new Win());
}

void			GameManager::initPlayer();
{
  _players[0] = (_mode != EVE) ? new Player() : new AI();
  _players[1] = (_mode != PVP) ? new AI() : new Player();
}

IGame *			GameManager::createGame();
{
  return new Game();
}

void			GameManager::changeMode(mode newMode);
{
  if (_mode == newMode)
    return ;
  _mode = newMode;
  // initPlayer() avec heritage des info
}

IGameMap::caseContent	GameManager::didClickCase(unsigned int x, unsigned y);
{

}
