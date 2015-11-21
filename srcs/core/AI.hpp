#ifndef AI_HPP_
# define AI_HPP_

# include "Player.hpp"

class AI : public Player
{
public:
  AI();
  AI(IPlayer *);

public:
  virtual ~AI() {}

private:
  color		_color;

public:
  virtual type		getType() const;
  virtual color		getColor() const;
};

#endif /* !AI_HPP_ */
