#include <iostream>
#include <cstring>
#include <fstream>
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
    static Case::dir dirs[] {Case::N, Case::NW, Case::W, Case::SW, Case::S, Case::SE, Case::E, Case::NE};
    static Case::pat2 pat2[] = {Case::YX, Case::YOX, Case::YOOX, Case::YOOOX};
    static Case::pat3 pat3[] = {Case::YXX, Case::YOXX, Case::YOOXX, Case::YXOX, Case::YXOOX, Case::YOXOX, Case::XYOX, Case::XYOOX, Case::XOYOX, Case::XYX};
    static Case::pat4 pat4[] = {Case::YXXX, Case::YOXXX, Case::YXOXX, Case::YXXOX, Case::XYXX, Case::XYOXX, Case::XYXOX};
    static Case::pat5 pat5[] = {Case::YXXXX, Case::XYXXX, Case::XXYXX};

    if (!cas.getPosable(aiColor))
        return 0;
    for (Case::dir dir : dirs) {
    for (Case::pat2 pat : pat2) {
        if (cas.getValue2(dir, pat, aiColor))
            ret += 16;
        if (cas.getValue2(dir, pat, noaiColor))
            ret -= 16;
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
