#include "BasicCheck.hpp"
#include "Game.hpp"

BasicCheck::BasicCheck()
  : _lastError()
{}

std::string const	&BasicCheck::getRuleName() const
{
  return "BasicCheck";
}

std::string const	&BasicCheck::getError() const
{
  return _lastError;
}

bool			BasicCheck::isOk(Game * game)
{
  // case empty ?
  return (game.getMap().getCase(game.getAction().getX(), game.getAction().getY()) == EMPTY);
}
