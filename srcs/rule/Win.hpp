#ifndef WIN_HPP_
# define WIN_HPP_

# include <string>

class Win : IRule
{
public:
  Win();

  virtual ~Win() {}

private:
  std::string		_lastError;

public:
  bool			isOk();
  std::string const	&getRuleName() const;
  std::string const	&getError() const;
};

#endif /* !WIN_HPP_ */
