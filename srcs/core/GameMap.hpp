#ifndef GAMEMAP_HPP_
# define GAMEMAP_HPP_

# include "DoubleThree.hpp"
# include "IJudge.hpp"
# include "IGame.hpp"
# include "IGameMap.hpp"
# include "Case.hpp"
# include <list>
# include <tuple>

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
    static const bool aiColor = true;
    static const bool noaiColor = false;

public:
    const int    dir[8][2] = {
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1}
    };
    
public:
    GameMap(IGame *);
    virtual ~GameMap();
    GameMap(GameMap&);

private:
    Case	_map[size_x][size_y];

public:
    typedef std::tuple<int, unsigned int, unsigned int> noteType;
    
private:
    std::list<noteType> _minList;
    std::list<noteType> _maxList;
    
private:
    bool    checkPat2(unsigned int x, unsigned int y, unsigned int d, bool color);
    bool    checkPat2YX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat2YOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat2YOOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat2YOOOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    
    bool    checkPat3(unsigned int x, unsigned int y, unsigned int d, bool color);
    bool    checkPat3YXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3YOXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3YOOXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3YXOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3YXOOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3YOXOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3XYOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3XYOOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3XOYOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat3XYX(unsigned int x, unsigned int y, Case::dir d, bool color);
    
    bool    checkPat4(unsigned int x, unsigned int y, unsigned int d, bool color);
    bool    checkPat4YXXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4YOXXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4YXOXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4YXXOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4XYXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4XYOXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat4XYXOX(unsigned int x, unsigned int y, Case::dir d, bool color);
    
    bool    checkPat5(unsigned int x, unsigned int y, unsigned int d, bool color);
    bool    checkPat5YXXXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat5XYXXX(unsigned int x, unsigned int y, Case::dir d, bool color);
    bool    checkPat5XXYXX(unsigned int x, unsigned int y, Case::dir d, bool color);

public:
    virtual void		clear();
    virtual void        update(unsigned int x, unsigned int y, bool color);
    virtual Case&		getCase(unsigned int x, unsigned int y);
    virtual void		setCase(unsigned int x, unsigned int y, Case::caseContent);
    virtual bool		isIn(unsigned int x, unsigned int y) const;
    void print();
    int evaluate(std::pair<int, int> move, bool isAI);
    std::list<noteType> getMaxMoves();
    std::list<noteType> const& getMinMoves();
    GameMap &operator =(GameMap &unit);
protected:
    static DoubleThree         _three;
    IGame*              _game;
};

#endif /* !GAMEMAP_HPP_ */
