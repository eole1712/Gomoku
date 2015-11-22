#ifndef IJUDGE_H_
# define IJUDGE_H_

# include <string>

class IGame;
class IRule;

class IJudge
{
public:
  virtual ~IJudge() {}

public:
  virtual std::string const	&getLastError() const = 0;
  virtual bool			checkRules(IGame *) = 0;

public:
  virtual void			addRule(IRule *) = 0;
  virtual void			removeRule(IRule::RuleType ruleType) = 0;
};


#endif /* !IJUDGE_H_ */
