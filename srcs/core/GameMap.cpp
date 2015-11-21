#include "IGameMap.hpp"
#include "GameMap.hpp"

GameMap::GameMap()
{
  clear();
}

void		GameMap::clear()
{
  for (int x = 0; x < 19; x++)
    for (int y = 0; y < 19; y++)
      _map[x][y] = EMPTY;
}

IGameMap::caseContent	GameMap::getCase(unsigned int x, unsigned int y) const
{
  return _map[x][y];
}

bool			GameMap::isIn(unsigned int x, unsigned int y) const
{
  return (x < 19 && y < 19);
}

void		GameMap::setCase(unsigned int x, unsigned int y, IGameMap::caseContent content)
{
  _map[x][y] = content;
}
