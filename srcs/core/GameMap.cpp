#include <iostream>
#include "IGameMap.hpp"
#include "GameMap.hpp"
#include "Case.hpp"

GameMap::GameMap()
{
    for (unsigned int x = 0; x < size_x; x++)
        for (unsigned int y = 0; y < size_y; y++)
            _map[x][y] = Case();
}

GameMap::~GameMap()
{
    clear();
}

GameMap::GameMap(GameMap &unit)
{
    std::memcpy(&unit._map[0][0], &_map[0][0], sizeof(_map));
}

void		GameMap::clear()
{
    for (unsigned int x = 0; x < size_x; x++)
        for (unsigned int y = 0; y < size_y; y++)
            _map[x][y].clear();
}

Case&	GameMap::getCase(unsigned int x, unsigned int y)
{
    return _map[x][y];
}

void		GameMap::setCase(unsigned int x, unsigned int y, Case::caseContent content)
{
    _map[x][y].setContent(content);
}

bool			GameMap::isIn(unsigned int x, unsigned int y) const
{
    return (x < size_x && y < size_y);
}
