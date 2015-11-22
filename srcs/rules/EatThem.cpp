#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "EatThem.hpp"

EatThem::EatThem()
  : _lastError("Eat them error")
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
  	    this->checkBetween(game, posX, posY, posX + x, posY + y);
  	  }
  // return à gérer
  return (true);
}

void EatThem::checkBetween(IGame* game, unsigned int posX, unsigned int posY, unsigned int x, unsigned int y)
{
  IGameMap::caseContent case1;
  IGameMap::caseContent case2;

  case1 = game->getMap()->getCase(x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
  case2 = game->getMap()->getCase(x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));

  if (case1 == ((game->getMap()->getCase(posX, posY) == IGameMap::caseContent::RED) ? IGameMap::caseContent::BLUE : IGameMap::caseContent::RED) && case1 == case2)
  {
      eat(game, x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
      eat(game, x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));
  }

 }

//TODO SET CASE COLOR TO GRAY
void	EatThem::eat(IGame* game, unsigned int posX, unsigned int posY)
{
  game->setCase(posX, posY, IGameMap::caseContent::EMPTY);
  game->getActivePlayer()->addPoints(1);
}
