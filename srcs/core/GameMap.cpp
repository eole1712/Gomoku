#include "IGameMap.hpp"
#include "GameMap.hpp"

GameMap::GameMap()
{
  clear();
}

GameMap::~GameMap()
{}

void		GameMap::clear()
{
  for (unsigned int x = 0; x < size_x; x++)
    for (unsigned int y = 0; y < size_y; y++)
      _map[x][y] = EMPTY;
}

IGameMap::caseContent	GameMap::getCase(unsigned int x, unsigned int y) const
{
  return _map[x][y];
}

bool			GameMap::isIn(unsigned int x, unsigned int y) const
{
  return (x < size_x && y < size_y);
}

void		GameMap::setCase(unsigned int x, unsigned int y, IGameMap::caseContent content)
{
  _map[x][y] = content;
}
