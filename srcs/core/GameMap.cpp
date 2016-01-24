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
    return getCase(x + dir[d][0], y + dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3(unsigned int x, unsigned int y, unsigned int d, bool color) {
    bool ret = false;
    bool tmp;
    
    tmp = checkPat3YXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3YOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YOXX, color, tmp);
    ret = ret | tmp;
    tmp = checkPat3YOOXX(x, y, (Case::dir)((d + 4) % 8), color);
    getCase(x, y).setValue3((Case::dir)((d + 4) % 8), Case::YOOXX, color, tmp);
    ret = ret | tmp;
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;

}

bool    GameMap::checkPat3YOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3XYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XYOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XOYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    std::cout << "D : " << (int)d << "(" << x - 2 * dir[d][0] << ", " << y - 2 * dir[d][1] << ")" << std::endl;
    if (x + 2 * dir[d][0] > 18 ||  x + 2 * dir[d][0] > 0 || y + 2 * dir[d][1] > 18 || y + 2 * dir[d][1] > 0)
        return false;
    if (x - 2 * dir[d][0] > 18 ||  2 * dir[d][0] > (int)x || y - 2 * dir[d][1] > 18 || 2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).getColor() == color) &&
    (getCase(x - dir[d][0], y - dir[d][1]).isEmpty() == true  || getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
    
}

bool    GameMap::checkPat3XYX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 1 * dir[d][0] > 18 ||  -1 * dir[d][0] > (int)x || y + 1 * dir[d][1] > 18 || -1 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
        (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color);
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YOXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 4 * dir[d][0] > 18 ||  -4 * dir[d][0] > (int)x || y + 4 * dir[d][1] > 18 || -4 * dir[d][1] > (int)y)
        return false;
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color)  &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XYXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 3 * dir[d][0] > 18 ||  -3 * dir[d][0] > (int)x || y + 3 * dir[d][1] > 18 || -3 * dir[d][1] > (int)y)
        return false;
    if (x - 1 * dir[d][0] > 18 ||  1 * dir[d][0] > (int)x || y - 1 * dir[d][1] > 18 || 1 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XXYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    if (x + 2 * dir[d][0] > 18 ||  -2 * dir[d][0] > (int)x || y + 2 * dir[d][1] > 18 || -2 * dir[d][1] > (int)y)
        return false;
    if (x - 2 * dir[d][0] > 18 ||  2 * dir[d][0] > (int)x || y - 2 * dir[d][1] > 18 || 2 * dir[d][1] > (int)y)
        return false;
    return (getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).getColor() == color) &&
    (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
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
            
            if (!checkPat2(tx, ty, d, color)) {
                break;
            }
            if (!checkPat3(tx, ty, d, color)) {
                break;
            }
            if (!checkPat4(tx, ty, d, color)) {
                break;
            }
            checkPat5(tx, ty, d, color);
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
