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
  const vec2		limit = { -1, 19 };

  const vec2		direction[8] =
    {
      {0, 1},
      {-1, 1},
      {-1, 0},
      {-1, -1},
      {0, -1},
      {1, -1},
      {1, 0},
      {1, 1}
    };

private:

  const std::string	_lastError;
  Case::caseContent	_myCell;
  bool			_color;
  IGameMap *		_map;

  bool			findDoubleThreeByAxis(vec2 const &, Case const &, unsigned int) const;
  bool			findThreeAlignFreeByAxis(vec2 const &, Case const &, unsigned int,
						 std::pair<vec2, vec2> &) const;
};

#endif /* !DOUBLETHREE_HPP_ */
