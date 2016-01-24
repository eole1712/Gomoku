#include <iostream>
#include <cstring>
#include <fstream>
#include <random>
#include "IGameMap.hpp"
#include "GameMap.hpp"
#include "Case.hpp"

GameMap::GameMap()
{
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<> dis(0, 19);
    
    for (unsigned int x = 0; x < size_x; x++)
        for (unsigned int y = 0; y < size_y; y++)
            _map[x][y] = Case();
    
    for (int i = 0; i < 10; i++) {
        _minList.push_back(noteType(0, dis(gen), dis(gen)));
        _maxList.push_back(noteType(0, dis(gen), dis(gen)));
    }
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

bool    GameMap::checkPat2(unsigned int x, unsigned int y, unsigned int d, bool color)
{
    bool ret = false;
    bool tmp;
    
    tmp = checkPat2YX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue2((Case::dir)((d + 4) % 8), Case::YX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat2YOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue2((Case::dir)((d + 4) % 8), Case::YX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat2YOOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue2((Case::dir)((d + 4) % 8), Case::YX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat2YOOOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue2((Case::dir)((d + 4) % 8), Case::YX, color, tmp);
    return ret | tmp;
}

bool GameMap::checkPat2YX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 1 * dir[d][0] > 18 ||  -1 * dir[d][0] > (int)x || y + 1 * dir[d][1] > 18 || -1 * dir[d][1] > (int)y)
        return false;
    return getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3(unsigned int x, unsigned int y, unsigned int d, bool color) {
    bool ret = false;
    bool tmp = false;
    
    tmp = checkPat3YXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YXX, color, tmp);
    ret = ret | tmp;
    if (tmp == true)
        std::cout << "B" << std::endl;
    tmp = checkPat3YOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YOXX, color, tmp);
    ret = ret | tmp;
    if (tmp == true)
        std::cout << "C" << std::endl;
    tmp = checkPat3YOOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YOOXX, color, tmp);
    ret = ret | tmp;
    if (tmp == true)
        std::cout << "D" << std::endl;
    tmp = checkPat3YXOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YXOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3YXOOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YXOOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3YOXOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YOXOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::XYOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYOOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::XYOOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XOYOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::XOYOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::XYX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYOX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue3((Case::dir)((d)), Case::XYOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYOOX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue3((Case::dir)((d)), Case::XYOOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XOYOX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue3((Case::dir)((d)), Case::XOYOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3XYX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue3((Case::dir)((d)), Case::XYX, color, tmp);
    return ret | tmp;
}

bool    GameMap::checkPat3YXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;
    
}

bool    GameMap::checkPat3YOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3XYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XYOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XOYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  x + 2 * dir[d][0] > 0 || y + 2 * dir[d][1] > 18 || y + 2 * dir[d][1] > 0)
        return false;
    if (x - 2 * dir[d][0] > 18 ||  2 * dir[d][0] > (int)x || y - 2 * dir[d][1] > 18 || 2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).isEmpty() == false && getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).getColor() == color) &&
    (getCase(x - dir[d][0], y - dir[d][1]).isEmpty() == true  || getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
    
}

bool    GameMap::checkPat3XYX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 1 * dir[d][0] > 18 ||  -1 * dir[d][0] > (int)x || y + 1 * dir[d][1] > 18 || -1 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4(unsigned int x, unsigned int y, unsigned int d, bool color) {
    bool ret = false;
    bool tmp;
    
    tmp = checkPat4YXXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::YXXX, color, tmp);
    ret = ret | tmp;
    
    tmp = checkPat4YOXXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::YOXXX, color, tmp);
    ret = ret | tmp;
    
    tmp = checkPat4YXOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::YXOXX, color, tmp);
    ret = ret | tmp;
    
    tmp = checkPat4YXXOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::YXXOX, color, tmp);
    ret = ret | tmp;
    
    tmp = checkPat4XYXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::XYXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat4XYOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::XYOXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat4XYXOX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue4((Case::dir)((d + 4) % 8), Case::XYXOX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat4XYXX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue4((Case::dir)((d)), Case::XYXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat4XYOXX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue4((Case::dir)((d)), Case::XYOXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat4XYXOX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue4((Case::dir)((d)), Case::XYXOX, color, tmp);
    return ret | tmp;
}

bool    GameMap::checkPat4YXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YOXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color)  &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5(unsigned int x, unsigned int y, unsigned int d, bool color) {
    bool ret = false;
    bool tmp;
    
    tmp = checkPat5YXXXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue5((Case::dir)((d + 4) % 8), Case::YXXXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat5XYXXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue5((Case::dir)((d + 4) % 8), Case::XYXXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat5XYXXX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue5((Case::dir)((d)), Case::XYXXX, color, tmp);
    ret = ret | tmp;
    
    tmp = checkPat5XXYXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue5((Case::dir)((d + 4) % 8), Case::XXYXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat5XXYXX(x, y, (Case::dir)((d)), color);
    getCase(x, y).setValue5((Case::dir)((d)), Case::XXYXX, color, tmp);
    
    return ret | tmp;
}

bool    GameMap::checkPat5YXXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).isEmpty() == false && getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XYXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == false && getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XXYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 2 * dir[d][0] > 18 ||  2 * dir[d][0] > (int)x || y - 2 * dir[d][1] > 18 || 2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).isEmpty() == false && getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).getColor() == color) &&
    (getCase(x - 1 * dir[d][0], y - 1 * dir[d][1]).isEmpty() == false && getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + 1 * dir[d][0], y + 1 * dir[d][1]).isEmpty() == false && getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == false && getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

void    GameMap::update(unsigned int x, unsigned int y, bool color)
{
    for (unsigned int d = 0; d < 8; d++)
    {
        for (unsigned int p = 1; p < 5; p++)
        {
            unsigned int tx = x + dir[d][0] * p;
            unsigned int ty = y + dir[d][1] * p;
            
            if (tx > 18 || ty > 18)
                break;
            
            if (checkPat2(tx, ty, d, color) == false) {
                break;
            }
            
            if (checkPat3(tx, ty, d, color) == false) {
                evaluate(std::make_pair(tx, ty), color);
                break;
            }
            if (checkPat4(tx, ty, d, color) == false) {
                evaluate(std::make_pair(tx, ty), color);
                break;
            }
            checkPat5(tx, ty, d, color);
            evaluate(std::make_pair(tx, ty), color);
        }
        
    }
}

void		GameMap::setCase(unsigned int x, unsigned int y, Case::caseContent content)
{
    bool color = content == Case::EMPTY ? _map[x][y].getColor() : (content == Case::RED);
    
    _map[x][y].setContent(content);
    update(x, y, color);
}

bool			GameMap::isIn(unsigned int x, unsigned int y) const
{
    return (x < size_x && y < size_y);
}

int GameMap::evaluate(std::pair<int, int> move, bool isAI)
{
    Case& cas = getCase(move.first, move.second);
    int ret = 0;
    static Case::dir dirs[] {Case::N, Case::NW, Case::W, Case::SW, Case::S, Case::SE, Case::E, Case::NE};
    static Case::pat2 pat2[] = {Case::YX, Case::YOX, Case::YOOX, Case::YOOOX};
    static Case::pat3 pat3[] = {Case::YXX, Case::YOXX, Case::YOOXX, Case::YXOX, Case::YXOOX, Case::YOXOX, Case::XYOX, Case::XYOOX, Case::XOYOX, Case::XYX};
    static Case::pat4 pat4[] = {Case::YXXX, Case::YOXXX, Case::YXOXX, Case::YXXOX, Case::XYXX, Case::XYOXX, Case::XYXOX};
    static Case::pat5 pat5[] = {Case::YXXXX, Case::XYXXX, Case::XXYXX};
    
    if (!cas.getPosable(aiColor))
        return 0;
    

    for (Case::dir dir : dirs) {
        for (Case::pat2 pat : pat2) {
            if (cas.getValue2(dir, pat, aiColor)) {
                std::cout << ">2<" << std::endl;
                ret += 16;
            }
            if (cas.getValue2(dir, pat, noaiColor)) {
                std::cout << ">-2<" << std::endl;
                ret -= 16;
            }
        }
        for (Case::pat3 pat : pat3) {
            if (cas.getValue3(dir, pat, aiColor))
                ret += 64;
            if (cas.getValue3(dir, pat, noaiColor))
                ret -= 64;
        }
        for (Case::pat4 pat : pat4) {
            if (cas.getValue4(dir, pat, aiColor))
                ret += 256;
            if (cas.getValue4(dir, pat, noaiColor))
                ret -= 256;
        }
        for (Case::pat5 pat : pat5) {
            if (cas.getValue5(dir, pat, aiColor))
                ret += 1024;
            if (cas.getValue5(dir, pat, noaiColor))
                ret -= 1024;
        }
    }

    std::cout << ret << std::endl;
    
    if (isAI) {
        _maxList.push_back(noteType(ret, move.first, move.second));
        
        _maxList.sort([](noteType a, noteType b){
            return (std::get<0>(a) > std::get<0>(b));
        });
//        if (_maxList.size() > 10)
//            _maxList.pop_back();
    } else {
        _minList.push_back(noteType(ret, move.first, move.second));
        
        _minList.sort([](noteType a, noteType b){
            return (std::get<0>(a) < std::get<0>(b));
        });
        
//        if (_minList.size() > 10)
//            _minList.pop_back();
    }
    for (Case::pat4 pat : pat4) {
        if (cas.getValue4(dir, pat, aiColor))
            ret += 256;
        if (cas.getValue4(dir, pat, noaiColor))
            ret -= 256;
    }
    for (Case::pat5 pat : pat5) {
        if (cas.getValue5(dir, pat, aiColor))
            ret += 1024;
        if (cas.getValue5(dir, pat, noaiColor))
            ret -= 1024;
    }
    }
    return ret;
}

void    GameMap::print()
{
    static std::pair<std::string, Case::dir> dirs[] {{"N", Case::N}, {"NW", Case::NW}, {"W", Case::W}, {"SW", Case::SW}, {"S", Case::S}, {"SE", Case::SE}, {"E", Case::E}, {"NE", Case::NE} };
    static std::pair<std::string, Case::pat2> pat2[] = { {"YX", Case::YX}, {"YOX", Case::YOX}, {"YOOX", Case::YOOX}, {"YOOOX", Case::YOOOX}};
    static std::pair<std::string, Case::pat3> pat3[] = {{"YXX", Case::YXX}, {"YOXX", Case::YOXX}, {"YOOXX", Case::YOOXX}, {"YXOX", Case::YXOX},
        {"YXOOX", Case::YXOOX}, {"YOXOX", Case::YOXOX}, {"XYOX", Case::YOXOX},
        {"XYOOX", Case::XYOOX}, {"XOYOX", Case::XOYOX}, {"XYX", Case::XYX}};
    static std::pair<std::string, Case::pat4> pat4[] = {{"YXXX", Case::YXXX}, {"YOXXX", Case::YOXXX}, {"YXOXX", Case::YXOXX}, {"YXXOX", Case::YXXOX},
        {"XYXX", Case::XYXX}, {"XYOXX", Case::XYOXX}, {"XYXOX", Case::XYXOX}};
    static std::pair<std::string, Case::pat5> pat5[] = {{"YXXXX", Case::YXXXX}, {"XYXXX", Case::XYXXX}, {"XXYXX", Case::XXYXX}};
    std::ofstream os;

    os.open("../Gomoku/map.json");

    std::cout << "file created" << std::endl;
    os << "{\n\"Map\" :" << std::endl;
    os << "[" << std::endl;
    bool first = true;
    for (auto& cases : _map)
    {
        for (auto& cas : cases) {
            os << (first ? "{" : ",{") << std::endl;
            if (first)
                first = false;
            os << "\"posable\" : " << (cas.getPosable(aiColor) ? "\"true\"" : "\"false\"")  << ", " << std::endl;

            for (std::pair<std::string, Case::dir> dir : dirs) {
                os << "\"" << dir.first << "\" : { " << std::endl;
                for (std::pair<std::string, Case::pat2> pat : pat2) {
                    std::string str = cas.getValue2(dir.second, pat.second, aiColor) ? "\"true\"" : "\"false\"";
                    os << "\"Ai" << pat.first << "\" : " << str << ", " << std::endl;
                    str = cas.getValue2(dir.second, pat.second, noaiColor) ? "\"true\"" : "\"false\"";
                    os << "\"noAi" << pat.first << "\" : " << (cas.getValue2(dir.second, pat.second, noaiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                }
                for (std::pair<std::string, Case::pat3> pat : pat3) {
                    os << "\"Ai" << pat.first << "\" : " << (cas.getValue3(dir.second, pat.second, aiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                    os << "\"noAi" << pat.first << "\" : " << (cas.getValue3(dir.second, pat.second, noaiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                }
                for (std::pair<std::string, Case::pat4> pat : pat4) {
                    os << "\"Ai" << pat.first << "\" : " << (cas.getValue4(dir.second, pat.second, aiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                    os << "\"noAi" << pat.first << "\" : " << (cas.getValue4(dir.second, pat.second, noaiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                }
                for (std::pair<std::string, Case::pat5> pat : pat5) {
                    os << "\"Ai" << pat.first << "\" : " << (cas.getValue5(dir.second, pat.second, aiColor) ? "\"true\"" : "\"false\"") << ", " << std::endl;
                    os << "\"noAi" << pat.first << "\" : " << (cas.getValue5(dir.second, pat.second, noaiColor) ? "\"true\"" : "\"false\"") << ((pat.second == Case::XXYXX) ? "" : ", ") << std::endl;
                }
                os << (dir.second == Case::NE ? "}" : "},") << std::endl;
            }
            os << "}" << std::endl;
        }
    }
    os << "]}" << std::endl;
}
