#ifndef IRULE_H_
# define IRULE_H_

# include <string>
# include "IGame.hpp"

class IRule
{
public:
  virtual ~IRule() {}

public:
  enum				RuleType { BASICCHECK = 0, WIN, EATTHEM };

  virtual RuleType		getRuleType() const = 0;
  virtual std::string const	&getError() const = 0;
  virtual bool			isOk(IGame *) = 0;
};

#endif /* !IRULE_H_ */
