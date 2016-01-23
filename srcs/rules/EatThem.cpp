#include <iostream>
#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "Case.hpp"
#include "EatThem.hpp"

EatThem::EatThem()
  : _lastError("ON S'EN FOU")
{}

EatThem::~EatThem()
{}

IRule::RuleType	EatThem::getRuleType() const
{
  return (IRule::EATTHEM);
}

std::string const&	EatThem::getError() const
{
  return (_lastError);
}

bool	EatThem::isOk(IGame* game)
{
  int			posX = game->getActivePlayer()->getX();
  int			posY = game->getActivePlayer()->getY();
  IGameMap*		map = game->getMap();
  Case::caseContent	masterColor = static_cast<Case::caseContent>(game->getActivePlayer()->getColor());

  for (int y = -3; y <= 3; y = y + 3)
    for (int x = -3; x <= 3; x = x + 3)
      if (map->isIn(posX + x, posY + y))
  	if (map->getCase(posX + x, posY + y).getContent() == masterColor)
  	  {
  	    this->checkBetween(game, posX, posY, posX + x, posY + y);
  	  }
  return (true);
}

void EatThem::checkBetween(IGame* game, unsigned int posX, unsigned int posY, unsigned int x, unsigned int y)
{
  Case::caseContent case1;
  Case::caseContent case2;

  case1 = game->getMap()->getCase(x + (posX > x) - (posX < x),
				  y + (posY > y) - (posY < y)).getContent();
  case2 = game->getMap()->getCase(x + 2 * ((posX > x) - (posX < x)),
				  y + 2 * ((posY > y) - (posY < y))).getContent();


  if (case1 == ((static_cast<Case::caseContent>(game->getActivePlayer()->getColor()) == Case::caseContent::RED) ? Case::caseContent::BLUE : Case::caseContent::RED) && case1 == case2)
  {
      eat(game, x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
      eat(game, x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));
  }

 }

void	EatThem::eat(IGame* game, unsigned int posX, unsigned int posY)
{
  game->setCase(posX, posY, Case::caseContent::EMPTY);
  game->getActivePlayer()->addPoints(1);
}
