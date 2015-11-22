#ifndef IRULE_H_
# define IRULE_H_

# include <string>

class IGame;

class IRule
{
public:
  virtual ~IRule() {}

public:
  enum				RuleType { BASICCHECK = 0, DOUBLETHREE, EATTHEM, WIN };

  virtual RuleType		getRuleType() const = 0;
  virtual std::string const	&getError() const = 0;
  virtual bool			isOk(IGame *) = 0;
};

#endif /* !IRULE_H_ */
