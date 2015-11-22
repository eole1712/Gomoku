#ifndef DOUBLETHREE_HPP_
# define DOUBLETHREE_HPP_

# include <string>
# include "IRule.hpp"

class IGame;

class DoubleThree : public IRule
{
public:
  DoubleThree();
  virtual ~DoubleThree();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const&	getError() const;
  virtual bool			isOk(IGame*);

private:
  std::string		_lastError;
};

#endif /* !DOUBLETHREE_HPP_ */
