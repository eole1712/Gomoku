#include "GameManager.hpp"

GameManager::GameManager(mode gameMode)
  : _game(createGame())
{
  initJudge();
}

GameManager::~GameManager()
{
  delete _game;
}

bool			GameManager::initJudge()
{
  // ne pas modifier l'ordre des régles !
  _judge.addRule(new basicCheck());
  // ...
  _judge.addRule(new Win());
  _judge.addRule(new EatThem());
}

Judge *			GameManager::getJudge() const
{
  return _judge;
}


Game *			GameManager::createGame()
{
  return new Game();
}

Game *			GameManager::getGame() const
{
  return _game;
}

IGameMap::caseContent	GameManager::didClickCase(unsigned int x, unsigned y) const
{
  return game.play(&_judge, x, y);
}
