#include "IPlayer.hpp"
#include "Player.hpp"
#include "AI.hpp"

const std::pair<int, int> AI::_default = {0,0};

AI::AI(IPlayer::color color)
  : Player(color)
{
}

AI::AI(IPlayer *player)
  : Player(player->getColor())
{
}

std::pair<int, int> AI::play(IGameMap* map)
{
    _minMax = nullptr;
    setMap(map);
    std::pair<int, int> move =  _minMax->evaluate(_depth);
    std::cout << "final move : " << move.first << ", " << move.second << std::endl;
    return move;
}

void AI::setMap(IGameMap *map)
{
    if (_minMax == nullptr)
        _minMax = new MinMax(*(dynamic_cast<GameMap*>(map)));
}

IPlayer::type		AI::getType() const
{
  return IPlayer::AI;
}
