#include "GameManager.hpp"

GameManager::GameManager(mode gameMode)
  : _mode(gameMode), _turn(false), _game(createGame())
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
  _judge.addRule(new basicCheck());
  // ...
  _judge.addRule(new Win());
  _judge.addRule(new EatThem());
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
  _players[0] = (_mode != EVE) ? new Player(_players[0]) : new AI(_players[0]);
  _players[1] = (_mode != PVP) ? new AI(_players[1]) : new Player(_players[1]);
  // initPlayer() avec heritage des info
}

mode			GameManager::getMode() const
{
  return _mode;
}

Game *			GameManager::getGame() const
{
  return _game;
}

IGameMap::caseContent	GameManager::didClickCase(unsigned int x, unsigned y);
{
  game.setAction(player[_turn], x, y);
  if (!_judge.checkRules(game))
    return game.getMap().getCase(x, y);
  _turn = !_turn;
  // if ai ? player[_turn].play(_game.getMap());
  return player[!_turn].getColor();
}
