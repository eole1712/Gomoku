#ifndef HUMAN_HPP_
# define HUMAN_HPP_

# include "IPlayer.hpp"

class Human : public IPlayer
{
public:
  Human();
  Human(IPlayer *);

public:
  virtual ~Human() {}

private:
  color		_color;
  unsigned int	_position[2];

public:
  virtual type		getType() const;
  virtual color		getColor() const;
  virtual void		setPosition(unsigned int x, unsigned int y);
};

#endif /* !HUMAN_HPP_ */
