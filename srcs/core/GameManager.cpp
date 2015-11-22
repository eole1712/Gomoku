#include <iostream>
#include "Gui.hpp"
#include "IGame.hpp"
#include "Game.hpp"
#include "GameManager.hpp"
#include "BasicCheck.hpp"
#include "Win.hpp"
#include "Judge.hpp"
#include "EatThem.hpp"
#include "DoubleThree.hpp"
#include "IPlayer.hpp"

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
  _game = new Game(gameMode, _gui);
  return _game;
}

void			GameManager::removeGame()
{
  if (_game)
    delete _game;
  _game = NULL;
}

IGame *			GameManager::getGame() const
{
  return _game;
}

void	GameManager::didClickCase(unsigned int x, unsigned y)
{
  if (_game == NULL)
    return;

  _game->playTurn(x, y);

  if (_judge->checkRules(_game)) {
    _game->setCase(x, y, static_cast<IGameMap::caseContent>(_game->getActivePlayer()->getColor()));
    _game->endTurn();
    std::cout << "player 1 score : " << getGame()->getPlayer(0)->getPoints() << std::endl;
    std::cout << "player 2 score : " << getGame()->getPlayer(1)->getPoints() << std::endl;
  }
  else
    std::cout << _judge->getLastError() << std::endl;

  if (_game->isFinished())
    std::cout << "WINNNNNNNNNNNN" << std::endl;

  for (int x = 0; x < 19; x++)
    {
      for (int y = 0; y < 19; y++)
	{
	  std::cout << _game->getMap()->getCase(x, y);
	}
      std::cout << std::endl;
    }
}
