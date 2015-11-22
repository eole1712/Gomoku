#ifndef HUMAN_HPP_
# define HUMAN_HPP_

# include "Player.hpp"

class Human : public Player
{
public:
  Human(color);
  Human(IPlayer *);

public:
  virtual ~Human() {}

public:
  virtual type		getType() const;
};

#endif /* !HUMAN_HPP_ */
