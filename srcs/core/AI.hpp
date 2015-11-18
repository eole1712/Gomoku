#ifndef AI_HPP_
# define AI_HPP_

# include "IPlayer.hpp"

class AI : IPlayer
{
public:
  AI();

public:
  virtual ~AI() {}

private:
  color		_color;

public:
  type		getType();
  color		getColor();
};

#endif /* !AI_HPP_ */
