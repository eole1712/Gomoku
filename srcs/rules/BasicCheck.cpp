#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "BasicCheck.hpp"

BasicCheck::BasicCheck()
  : _lastError("Basic check error")
{}

BasicCheck::~BasicCheck()
{}

IRule::RuleType	BasicCheck::getRuleType() const
{
  return IRule::BASICCHECK;
}

std::string const	&BasicCheck::getError() const
{
  return _lastError;
}

bool			BasicCheck::isOk(IGame * game)
{
  int	posX = game->getActivePlayer()->getX();
  int	posY = game->getActivePlayer()->getY();

  if (!game->getMap()->isIn(posX, posY))
    return (false);
  return (game->getMap()->getCase(posX, posY) == GameMap::EMPTY);
}
