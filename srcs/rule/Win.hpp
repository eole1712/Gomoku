#ifndef WIN_HPP_
# define WIN_HPP_

# include <string>

class Win : public IRule
{
public:
  Win();

  virtual ~Win() {}

private:
  std::string		_lastError;

public:
  virtual bool			isOk(Game *);
  virtual std::string const	&getRuleName() const;
  virtual std::string const	&getError() const;
};

#endif /* !WIN_HPP_ */
