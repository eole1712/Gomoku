#include "IGameMap.hpp"
#include "GameMap.hpp"
#include "Case.hpp"

GameMap::GameMap()
{
  clear();
  for (unsigned int x = 0; x < size_x; x++)
    for (unsigned int y = 0; y < size_y; y++)
      _map[x][y] = new Case();
}

GameMap::~GameMap()
{}

void		GameMap::clear()
{
  for (unsigned int x = 0; x < size_x; x++)
    for (unsigned int y = 0; y < size_y; y++)
      if (_map[x][y] != nullptr)
	delete _map[x][y];
}

Case*	GameMap::getCase(unsigned int x, unsigned int y) const
{
  return _map[x][y];
}

void		GameMap::setCase(unsigned int x, unsigned int y, Case::caseContent content)
{
  _map[x][y]->setCaseContent(content);
}

bool			GameMap::isIn(unsigned int x, unsigned int y) const
{
  return (x < size_x && y < size_y);
}
