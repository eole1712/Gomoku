#include "IPlayer.hpp"
#include "AI.hpp"

AI::AI()
  : _color(BLUE)
{
}

AI::AI(IPlayer *player)
  : _color(player->getColor())
{
}

IPlayer::type		AI::getType() const
{
  return IPlayer::AI;
}

IPlayer::color		AI::getColor() const
{
  return _color;
}

void			AI::setPosition(unsigned int x, unsigned int y)
{
  _position[0] = x;
  _position[1] = y;
}
