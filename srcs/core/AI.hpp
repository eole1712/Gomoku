#ifndef AI_HPP_
# define AI_HPP_

# include "Player.hpp"
#include "MinMax.hpp"

class IPlayer;

class AI : public Player
{
public:
    AI(color);
    AI(IPlayer *);

public:
    virtual ~AI() {}
    std::pair<int, int> play(IGameMap*);
    void setMap(IGameMap* map);
private:
    color		_color;
    MinMax*   _minMax = nullptr;
    static const std::pair<int, int> _default ;
    static constexpr int _depth = 3;

public:
    virtual type		getType() const;
};

#endif /* !AI_HPP_ */
