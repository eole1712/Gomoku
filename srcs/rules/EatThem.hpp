#ifndef EATTHEM_HPP_
# define EATTHEM_HPP_

# include <string>
# include "IRule.hpp"
# include "Game.hpp"

class EatThem : public IRule
{
public:
  EatThem();
  virtual ~EatThem();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const&	getError() const;
  virtual bool			isOk(IGame*);

private:
  void			checkBetween(IGame* game, unsigned int posX, unsigned int posY,
				   unsigned int x, unsigned int y);
  void			eat(IGame* game, unsigned int posX, unsigned int posY);

private:
  std::string		_lastError;
};

#endif /* !EATTHEM_HPP_ */
