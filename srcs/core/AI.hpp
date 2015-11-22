#ifndef AI_HPP_
# define AI_HPP_

# include "Player.hpp"

class AI : public Player
{
public:
  AI(color);
  AI(IPlayer *);

public:
  virtual ~AI() {}

private:
  color		_color;

public:
  virtual type		getType() const;
};

#endif /* !AI_HPP_ */
