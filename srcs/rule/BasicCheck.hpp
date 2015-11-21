#ifndef BASICCHECK_HPP_
# define BASICCHECK_HPP_

# include <string>
# include "Game.hpp"

class BasicCheck : public IRule
{
public:
  BasicCheck();
  virtual ~BasicCheck();

public:
  std::string const&	getRuleName() const;
  std::string const&	getError() const;
  bool			isOk(Game*);

private:
  std::string		_lastError;
};

#endif /* !BASICCHECK_HPP_ */
