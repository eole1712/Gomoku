#ifndef GAMEMAP_HPP_
# define GAMEMAP_HPP_

# include "IGameMap.hpp"
# include "Case.hpp"

# include <list>

class GameMap
: public IGameMap
{
public:
    static const unsigned int	size_x = 19;
    static const unsigned int	size_y = 19;
  /*  static const vec2		DIR[8] = {{0, -1},
                                      {-1, -1},
                                      {-1, 0},
                                      {-1, 1},
                                      {0, 1},
                                      {1, 1},
                                      {1, 0},
                                      {1, -1}};*/
    static const Case::caseContent aiColor = Case::BLUE;
    static const Case::caseContent noaiColor = Case::RED;

public:
    GameMap();
    virtual ~GameMap();
    GameMap(GameMap &);

private:
    Case	_map[size_x][size_y];

public:
    virtual void		clear();
    virtual Case&		getCase(unsigned int x, unsigned int y);
    virtual void		setCase(unsigned int x, unsigned int y, Case::caseContent);
    virtual bool		isIn(unsigned int x, unsigned int y) const;
    void print();
    int evaluate(std::pair<int, int> move);
};

#endif /* !GAMEMAP_HPP_ */
