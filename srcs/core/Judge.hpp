#ifndef JUDGE_HPP_
# define JUDGE_HPP_

# include <map>
# include <string>
# include "IJudge.hpp"
# include "IRule.hpp"

class IGame;

class Judge : public IJudge
{
public:
  Judge();
  virtual ~Judge();

private:
  typedef std::map<IRule::RuleType, IRule *> ruleMap;

  ruleMap		_rules;
  std::string		_lastError;

public:
  virtual std::string const	&getLastError() const;
  virtual bool			checkRules(IGame *);

public:
  virtual void			addRule(IRule *);
  virtual void			removeRule(IRule::RuleType ruleType);
};

#endif /* !JUDGE_HPP_ */
