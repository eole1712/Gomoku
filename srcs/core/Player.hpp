#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "IPlayer.hpp"

class Player : public IPlayer
{
public:
  Player(color);
  virtual ~Player();

private:
  unsigned int _position[2];
  color   _color;
  unsigned int _points;

public:
	virtual unsigned int	getPoints() const;
	virtual void	addPoints(unsigned int points);
  virtual type		getType() const = 0;
  virtual color		getColor() const;
  virtual void		setPosition(unsigned int x, unsigned int y);
  virtual unsigned int	getX() const;
  virtual unsigned int	getY() const;

private:
};

#endif /* PLAYER_HPP_ */
