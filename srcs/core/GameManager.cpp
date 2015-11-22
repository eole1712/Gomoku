#include <iostream>
#include "IGame.hpp"
#include "GameManager.hpp"
#include "BasicCheck.hpp"
#include "Win.hpp"
#include "Judge.hpp"
#include "EatThem.hpp"

GameManager::GameManager()
  : _game(NULL)
{
  initJudge();
}

GameManager::~GameManager()
{
  if (_game)
    delete _game;
}

bool			GameManager::initJudge()
{
  _judge = new Judge();
  // ne pas modifier l'ordre des régles !
  _judge->addRule(new BasicCheck());
  // ...
  _judge->addRule(new Win());
  _judge->addRule(new EatThem());
  return true;
}

IJudge *		GameManager::getJudge() const
{
  return _judge;
}

IGame *			GameManager::createGame(IGame::mode gameMode)
{
  if (gameMode == IGame::PVE)
    return NULL;
  _game = new Game(gameMode);
  return _game;
}

IGame *			GameManager::getGame() const
{
  return _game;
}

IGameMap::caseContent	GameManager::didClickCase(unsigned int x, unsigned y) const
{
  if (_game == NULL)
    return IGameMap::EMPTY;

  std::cout << "playTurn" << std::endl;
  _game->playTurn(x, y);

  std::cout << "checkRules" << std::endl;
  _judge->checkRules(_game);

  std::cout << "endTurn" << std::endl;
  _game->endTurn();

  std::cout << "getCase" << std::endl;
  return _game->getMap()->getCase(x, y);
}
