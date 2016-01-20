#ifndef WIN_HPP_
# define WIN_HPP_

# include <string>
# include "IRule.hpp"
# include "vec2.hpp"

class IGame;

class Win : public IRule
{
public:
  Win();
  virtual ~Win();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const	&getError() const;
  virtual bool			isOk(IGame*);

private:
  bool				canEatThis(IGameMap *map, vec2 origin, vec2 axis,
					   IGameMap::caseContent v) const;

private:
  std::string		_lastError;
};

#endif /* !WIN_HPP_ */
