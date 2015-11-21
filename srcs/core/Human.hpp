#ifndef HUMAN_HPP_
# define HUMAN_HPP_

# include "Player.hpp"

class Human : public Player
{
public:
  Human();
  Human(IPlayer *);

public:
  virtual ~Human() {}

private:
  color		_color;

public:
  virtual type		getType() const;
  virtual color		getColor() const;
};

#endif /* !HUMAN_HPP_ */
