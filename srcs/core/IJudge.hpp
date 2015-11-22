#ifndef IJUDGE_H_
# define IJUDGE_H_

# include <string>
# include "IRule.hpp"
# include "IGame.hpp"

class IJudge
{
public:
  ~IJudge() {}

public:
  virtual std::string const	&getLastError() const = 0;
  virtual bool			checkRules(IGame *) = 0;

public:
  virtual void			addRule(IRule *) = 0;
  virtual void			removeRule(IRule::RuleType ruleType) = 0;
};


#endif /* !IJUDGE_H_ */
