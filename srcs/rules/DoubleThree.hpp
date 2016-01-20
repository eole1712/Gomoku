#ifndef DOUBLETHREE_HPP_
# define DOUBLETHREE_HPP_

#include <string>
#include "IRule.hpp"
#include "Case.hpp"
#include "vec2.hpp"

class IGame;

class DoubleThree : public IRule
{
  typedef std::pair<Case::caseContent, vec2> align;

public:
  DoubleThree();
  virtual ~DoubleThree();

public:
  virtual IRule::RuleType	getRuleType() const;
  virtual std::string const&	getError() const;
  virtual bool			isOk(IGame*);

private:
  const std::string	_lastError;
  const vec2		_axis[4];
  const vec2		_boundLimit;
  const Case::caseContent		_validCase[5][5];
  Case::caseContent	_enemyCell;
  Case::caseContent	_myCell;
  vec2			_playingPosition;
  IGameMap *		_map;
  bool			checkFreeAlign(vec2 const & origin, vec2 axis, align * alignOut);
  bool			haveSecondAlign(int const & originAxis, align * align);
};

#endif /* !DOUBLETHREE_HPP_ */
