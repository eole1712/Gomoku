#ifndef IRULE_H_
# define IRULE_H_

# include <string>
# include "IGame.hpp"

class IRule
{
public:
  virtual ~IRule() {}

public:
  virtual std::string const	&getRuleName() const;
  virtual std::string const	&getError() const;
  virtual bool			isOk(IGame *);
};

#endif /* !IRULE_H_ */
