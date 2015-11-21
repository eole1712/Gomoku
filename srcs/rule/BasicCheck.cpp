#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "BasicCheck.hpp"

BasicCheck::BasicCheck()
  : _lastError()
{}

IRule::RuleType	BasicCheck::getRuleType() const
{
  return IRule::BASICCHECK;
}

std::string const	&BasicCheck::getError() const
{
  return _lastError;
}

bool			BasicCheck::isOk(Game * game)
{
  // case empty -> [check]
  return (game->getMap()->getCase(game->getActivePlayer()->getX(),
				  game->getActivePlayer()->getY())
	  == GameMap::EMPTY);
}
