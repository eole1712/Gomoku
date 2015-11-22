#include "IGame.hpp"
#include "GameManager.hpp"
#include "BasicCheck.hpp"
#include "Win.hpp"
#include "Judge.hpp"
#include "EatThem.hpp"

GameManager::GameManager()
  : _game(NULL)
{
  _judge = new Judge();
  _judge->addRule(new BasicCheck());
  _judge->addRule(new DoubleThree());
  _judge->addRule(new EatThem());
  _judge->addRule(new Win());  initJudge();
}

GameManager::~GameManager()
{
  delete _game;
}

IJudge *		GameManager::getJudge() const
{
  return _judge;
}

IGame *			GameManager::createGame(IGame::mode gameMode)
{
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
  _game->playTurn(x, y);
  _judge->checkRules(_game);
  _game->endTurn();
  return _game->getMap()->getCase(x, y);
}
