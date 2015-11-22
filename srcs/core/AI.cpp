#include "IPlayer.hpp"
#include "Player.hpp"
#include "AI.hpp"

AI::AI(IPlayer::color color)
  : Player(color)
{
}

AI::AI(IPlayer *player)
  : Player(player->getColor())
{
}

IPlayer::type		AI::getType() const
{
  return IPlayer::AI;
}
