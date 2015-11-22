#include "Human.hpp"

Human::Human(IPlayer::color color)
  : Player(color)
{
}

Human::Human(IPlayer *player)
  : Player(player->getColor())
{

}

IPlayer::type		Human::getType() const
{
  return IPlayer::HUMAN;
}
