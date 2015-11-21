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

  virtual RuleType		getRuleType() const;
  virtual std::string const	&getError() const;
  virtual bool			isOk(IGame *);
};

#endif /* !IRULE_H_ */
