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
