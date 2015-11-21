Game::Game()
  : _map(), _mode(gameMode), _turn(false), _winner(NULL), _finish(false), _turn(false)
{
  initPlayer();
}

void		Game::initPlayer();
{
  _players[0] = (_mode != EVE) ? new Player() : new AI();
  _players[1] = (_mode != PVP) ? new AI() : new Player();
}

Player *	Game::getPlayer() const
{
  return _palyer;
}

Player *	Game::getActivePlayer() const
{
  return _players[_turn];
}

GameMap *	Game::getMap() const
{
  return _map;
}


mode		Game::getMode() const
{
  return _mode;
}

void		Game::channgeMode(mode newMode);
{
  if (_mode == newMode)
    return ;
  _mode = newMode;
  _players[0] = (_mode != EVE) ? new Player(_players[0]) : new AI(_players[0]);
  _players[1] = (_mode != PVP) ? new AI(_players[1]) : new Player(_players[1]);
  // initPlayer() avec heritage des info
}

IGameMap::caseContent	Game::play(Judge * judge, unsigned int x, unsigned int y)
{
  getActivePlayer().setPosition(x, y);
  if (!judge.checkRules(game))
    return game.getMap().getCase(x, y);
  _turn = !_turn;
  // if ai ? player[_turn].play(_game.getMap());
  return player[!_turn].getColor();
}

bool		Game::isFinished() const
{
  return _finish;
}

IPlayer *	Game::getWinner() const
{
  return _winner;
}
