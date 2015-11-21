#ifndef EATTHEM_HPP_
# define EATTHEM_HPP_

# include <string>
# include "Game.hpp"

class EatThem : IRule
{
public:
  EatThem();
  virtual ~EatThem()

public:
  std::string const&	getRuleName() const;
  std::string const&	getError() const;
  bool			isOk(Game*);

  void			eatBetween(unsigned int posX, unsigned int posY,
				   unsigned int x, unsigned int y);
  void			eat(unsigned int posX, unsigned int posY);

private:
  std::string		_lastError;
};

#endif /* !EATTHEM_HPP_ */
