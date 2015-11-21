#include "Human.hpp"

Human::Human()
  : _color(BLUE)
{
}

Human::Human(IPlayer *player)
  : _color(player->getColor())
{

}

IPlayer::type		Human::getType() const
{
  return IPlayer::HUMAN;
}

IPlayer::color		Human::getColor() const
{
  return _color;
}
