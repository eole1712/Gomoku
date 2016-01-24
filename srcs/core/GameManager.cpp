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
#include "AI.hpp"
#include "Case.hpp"

GameManager::GameManager(int &ac, char **av)
: _game(NULL)
{
    _judge = new Judge();
    _judge->addRule(new BasicCheck());
    _judge->addRule(new EatThem());
    _judge->addRule(new Win());
    _gui = new Gui(this, ac, av);
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
        _game->setCase(x, y, static_cast<Case::caseContent>(_game->getActivePlayer()->getColor()));
        _game->endTurn();
        _gui->showError("");

        std::pair<int, int> move;

        while (_game->getActivePlayer()->getType() == IPlayer::AI) {
            move = dynamic_cast<AI*>(_game->getActivePlayer())->play(_game->getMap());
            didClickCase(move.first, move.second);
        }
    }
    else if (_game->getActivePlayer()->getType() == IPlayer::HUMAN)
        _gui->showError(_judge->getLastError());
    for (unsigned int tx = 0; tx < 19; tx++)
        for (unsigned int ty = 0; ty < 19; ty++) {
            _game->getGui()->setPosable(tx, ty, _game->getMap()->getCase(tx, ty).getPosable(true), true);
            _game->getGui()->setPosable(tx, ty, _game->getMap()->getCase(tx, ty).getPosable(false), false);
        }
    // if (_game->isFinished())
    //   std::cout << "WINNNNNNNNNNNN" << std::endl;
    
    // affichage de la map (terminal)
    // for (int x = 0; x < 19; x++)
    //   {
    //     for (int y = 0; y < 19; y++)
    // 	{
    // 	  std::cout << _game->getMap()->getCase(x, y);
    // 	}
    //     std::cout << std::endl;
    //   }
}
