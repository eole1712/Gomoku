#ifndef AI_HPP_
# define AI_HPP_

# include "IPlayer.hpp"

class AI : public IPlayer
{
public:
  AI();
  AI(IPlayer *);

public:
  virtual ~AI() {}

private:
  unsigned int	_position[2];
  color		_color;

public:
  virtual type		getType() const;
  virtual color		getColor() const;
  virtual void		setPosition(unsigned int x, unsigned int y);
};

#endif /* !AI_HPP_ */
