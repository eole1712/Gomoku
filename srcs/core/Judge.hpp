#ifndef JUDGE_HPP_
# define JUDGE_HPP_

# include <map>
# include <string>
# include "IJudge.hpp"

class Judge : public IJudge
{
public:
  Judge();
  ~Judge() {}

private:
  typedef std::map<std::string, IRule *> ruleMap;

  ruleMap		_rules;
  std::string		_lastError;

public:
  virtual std::string const	&getLastError() const;
  virtual bool			checkRules(IGame *);

public:
  virtual void			addRule(IRule *);
  virtual void			removeRule(std::string const &ruleName);
};

#endif /* !JUDGE_HPP_ */
