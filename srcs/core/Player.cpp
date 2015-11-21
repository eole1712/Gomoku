#include "Player.hpp"

Player::Player()
  : _position{0}
{
}

Player::~Player()
{
}

void		Player::setPosition(unsigned int x, unsigned int y)
{
  _position[0] = x;
  _position[1] = y;

}

unsigned int	Player::getX() const
{
  return _position[0];
}

unsigned int	Player::getY() const
{
  return _position[1];
}
