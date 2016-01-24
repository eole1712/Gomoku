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

int GameMap::evaluate(std::pair<int, int> move)
{
    Case& cas = getCase(move.first, move.second);
    int ret = 0;
    static unsigned int pat2[] = {Case::YX, Case::YOX, Case::YOOX, Case::YOOOX};
    static unsigned int pat3[] = {Case::YXX, Case::YOXX, Case::YOOXX, Case::YXOX, Case::YXOOX, Case::YOXOX, Case::XYOX, Case::XYOOX, Case::XOYOX, Case::XYX};
    static unsigned int pat4[] = {Case::YXXX, Case::YOXXX, Case::YXOXX, Case::YXXOX, Case::XYXX, Case::XYOXX, Case::XYXOX};
    static unsigned int pat5[] = {Case::YXXXX, Case::XYXXX, Case::XXYXX};

    if (!cas.getPosable())
        return 0;
    for (int dir : DIR) {
    for (unsigned int pat : pat2) {
        if (cas.getValue2(dir, pat, aiColor))
            ret += 16;
        if (cas.getValue2(dir, pat, noaiColor))
            ret -= 16;
    }
    for (unsigned int pat : pat3) {
        if (cas.getValue3(dir, pat, aiColor))
            ret += 64;
        if (cas.getValue3(dir, pat, noaiColor))
            ret -= 64;
    }
    for (unsigned int pat : pat4) {
        if (cas.getValue4(dir, pat, aiColor))
            ret += 256;
        if (cas.getValue4(dir, pat, noaiColor))
            ret -= 256;
    }
    for (unsigned int pat : pat5) {
        if (cas.getValue4(dir, pat, aiColor))
            ret += 1024;
        if (cas.getValue4(dir, pat, noaiColor))
            ret -= 1024;
    }
    }
}

void    gameMap::print()
{
    for (auto& cas : _map)
    {
        std::cout << sizeof(cas) << std::endl;
    }
}
