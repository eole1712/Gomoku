#include "BasicCheck.hpp"

BasicCheck::BasicCheck()
  : _lastError()
{}

bool			BasicCheck::isOk(Game * game)
{
  // case empty ?
  return (game.getMap().getCase(game.getAction().getX(), game.getAction().getY()) == EMPTY);
}

std::string const	&BasicCheck::getRuleName() const
{
  return std::string("BasicCheck");
}

std::string const	&BasicCheck::getError() const
{
  return _lastError;
}
