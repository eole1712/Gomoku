#ifndef BASICCHECK_HPP_
# define BASICCHECK_HPP_

# include <string>
# include "IRule.hpp"
# include "Game.hpp"

class BasicCheck : public IRule
{
public:
  BasicCheck();
  virtual ~BasicCheck();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const&	getError() const;
  virtual bool			isOk(IGame*);

private:
  std::string		_lastError;
};

#endif /* !BASICCHECK_HPP_ */
