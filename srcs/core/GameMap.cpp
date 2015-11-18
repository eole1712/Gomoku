#include "GameMap.hpp"

GameMap::GameMap()
  : map{{0}}
{

}

void		GameMap::clear()
{
  map = {{0}};
}

caseContent	GameMap::getCase(unsigned int x, unsigned int y) const
{
  return map[x][y];
}

void		GameMap::setCase(unsigned int x, unsigned int y, caseContent content)
{
  map[x][y] = content;
}
