#ifndef PLAYER_HPP_
# define PLAYER_HPP_

#include "IPlayer.hpp"

class Player : public IPlayer
{
public:
  Player();
  virtual ~Player();

public:
  unsigned int _position[2];

public:
  virtual type		getType() const = 0;
  virtual color		getColor() const = 0;
  virtual void		setPosition(unsigned int x, unsigned int y);
  virtual unsigned int	getX() const;
  virtual unsigned int	getY() const;
};

#endif /* PLAYER_HPP_ */
