#ifndef BASICCHECK_HPP_
# define BASICCHECK_HPP_

# include <string>

class BasicCheck : IRule
{
public:
  BasicCheck();

  virtual ~BasicCheck() {}

private:
  std::string		_lastError;

public:
  bool			isOk(Game *);
  std::string const	&getRuleName() const;
  std::string const	&getError() const;
};

#endif /* !BASICCHECK_HPP_ */
