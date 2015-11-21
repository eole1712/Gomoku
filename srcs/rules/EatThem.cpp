#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "EatThem.hpp"

EatThem::EatThem()
  : _lastError()
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
  IGameMap::caseContent	masterColor = map->getCase(posX, posY);

  for (int y = -3; y <= 3; y = y + 3)
    for (int x = -3; x <= 3; x = x + 3)
      if (map->isIn(posX + x, posY + y))
  	if (map->getCase(posX + x, posY + y) == masterColor)
  	  {
  	    this->eatBetween(posX, posY, posX + x, posY + y);
  	    //TODO ADD 2 POINT TO PLAYER(masterColor);
  	  }
  // return à gérer
  return (true);
}

void EatThem::eatBetween(unsigned int posX, unsigned int posY, unsigned int x, unsigned int y)
{
  eat(x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
  eat(x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));
}

//TODO SET CASE COLOR TO GRAY
void	EatThem::eat(unsigned int, //posX,
		     unsigned int)// posY)
{}
