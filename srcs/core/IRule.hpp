#ifndef IRULE_H_
# define IRULE_H_

# include <string>

class IRule
{
public:
  virtual ~IRule() {}

public:
  virtual bool			isOk() const;
  virtual std::string const	&getRuleName() const;
  virtual std::string const	&getError() const;
};

#endif /* !IRULE_H_ */
