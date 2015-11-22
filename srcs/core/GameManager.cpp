#include <iostream>
#include "Gui.hpp"
#include "IGame.hpp"
#include "GameManager.hpp"
#include "BasicCheck.hpp"
#include "Win.hpp"
#include "Judge.hpp"
#include "EatThem.hpp"
#include "DoubleThree.hpp"

GameManager::GameManager()
  : _game(NULL)
{
  _judge = new Judge();
  _judge->addRule(new BasicCheck());
  _judge->addRule(new DoubleThree());
  _judge->addRule(new EatThem());
  _judge->addRule(new Win());
  _gui = new Gui(this, 0, nullptr);
}

GameManager::~GameManager()
{
  if (_game)
    delete _game;
  delete _judge;
 // delete _gui;
}

void        GameManager::start() const
{
  _gui->start();
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

void	GameManager::didClickCase(unsigned int x, unsigned y)
{
  if (_game == NULL)
    return;

  std::cout << "playTurn" << std::endl;
  _game->playTurn(x, y);

  std::cout << "checkRules" << std::endl;
  if (_judge->checkRules(_game)) {
    _gui->setButtonColor(x, y, static_cast<IGameMap::caseContent>(_game->getActivePlayer()->getColor()));
    _game->setCase(x, y, static_cast<IGameMap::caseContent>(_game->getActivePlayer()->getColor()));
  }
  else
    std::cout << _judge->getLastError() << std::endl;

  std::cout << "endTurn" << std::endl;
  _game->endTurn();

  std::cout << "getCase" << std::endl;
}
