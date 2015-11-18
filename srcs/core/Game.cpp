Game::Game()
  : _winner(NULL), _finish(false), _turn(false)
{
}

IGameMap *	Game::getMap() const
{
  return _map;
}

IPlayer *	Game::getPlayer() const
{
  return _palyer;
}

bool		Game::nextAction() const
{
  // ??
}

bool		Game::isFinished() const
{
  return _finish;
}

bool		Game::getTurn() const
{
  return _turn;
}

void		Game::setTurn(bool val)
{
  _turn = val
}

IPlayer *	Game::getWinner() const
{
  return _winner;
}
