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
    return getCase(x + dir[d][0], y + dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool GameMap::checkPat2YOOOX(unsigned int x, unsigned int y, Case::dir d, bool color)
{
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color;

}

bool    GameMap::checkPat3YOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YXOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3YOXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true  || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color;
}

bool    GameMap::checkPat3XYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XYOOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true  || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat3XOYOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - 2 * dir[d][0], y - 2 * dir[d][1]).getColor() == color) &&
    (getCase(x - dir[d][0], y - dir[d][1]).isEmpty() == true  || getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true  || getCase(x + dir[d][0], y * dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
    
}

bool    GameMap::checkPat3XYX(unsigned int x, unsigned int y, Case::dir d, bool color) {
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YOXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color || getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4YXXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color || getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).isEmpty() == true) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color)  &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYOXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color || getCase(x + dir[d][0], y + dir[d][1]).isEmpty() == true) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat4XYXOX(unsigned int x, unsigned int y, Case::dir d, bool color) {
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
    return (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color) &&
    (getCase(x + 4 * dir[d][0], y + 4 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XYXXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
    return (getCase(x - dir[d][0], y - dir[d][1]).getColor() == color) &&
    (getCase(x + dir[d][0], y + dir[d][1]).getColor() == color) &&
    (getCase(x + 2 * dir[d][0], y + 2 * dir[d][1]).getColor() == color) &&
    (getCase(x + 3 * dir[d][0], y + 3 * dir[d][1]).getColor() == color);
}

bool    GameMap::checkPat5XXYXX(unsigned int x, unsigned int y, Case::dir d, bool color) {
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
            Case c = getCase(x + dir[d][0] * p, y + dir[d][1] * p);
            if (!checkPat2(x + dir[d][0] * p,  y + dir[d][1] * p, d, color)) {
                break;
            }
            if (!checkPat3(x + dir[d][0] * p,  y + dir[d][1] * p, d, color)) {
                break;
            }
            if (!checkPat4(x + dir[d][0] * p,  y + dir[d][1] * p, d, color)) {
                break;
            }
            checkPat5(x + dir[d][0] * p,  y + dir[d][1] * p, d, color);
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
