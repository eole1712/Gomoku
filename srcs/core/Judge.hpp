#ifndef JUDGE_HPP_
# define JUDGE_HPP_

# include <map>
# include <string>
# include "IJudge.hpp"

class Judge : IJudge
{
public:
  Judge();
  ~Judge() {}

private:
  typedef std::map<std::string, IRule *> ruleMap;

  ruleMap		_rules;
  std::string		_lastError;

public:
  std::string const	&getLastError() const;
  bool			checkRules(IRule *);

public:
  void			addRule(IRule *);
  bool			removeRule(std::string const &ruleName);
}

#endif /* !JUDGE_HPP_ */
