#ifndef WIN_HPP_
# define WIN_HPP_

# include <string>
# include "IRule.hpp"
# include "Game.hpp"

class Win : public IRule
{
public:
  Win();
  virtual ~Win();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const	&getError() const;
  virtual bool			isOk(Game *);

private:
  std::string		_lastError;
};

#endif /* !WIN_HPP_ */
