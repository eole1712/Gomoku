#ifndef HUMAIN_HPP_
# define HUMAIN_HPP_

# include "IPlayer.hpp"

class Humain
{
public:
  Humain();

public:
  virtual ~Humain() {}

private:
  color		_color;

public:
  type		getType();
  color		getColor();
};

#endif /* !HUMAIN_HPP_ */
