#include "Player.hpp"

Player::Player(IPlayer::color color)
  : _position{0}, _color(color), _points(0)
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

void			Player::addPoints(unsigned int points)
{
	_points += points;
}

unsigned int	Player::getPoints() const
{
	return _points;
}

IPlayer::color		Player::getColor() const
{
  return _color;
}
