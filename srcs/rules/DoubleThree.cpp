#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "DoubleThree.hpp"

#include <iostream>

DoubleThree::DoubleThree()
  : _lastError(std::string("Regle des trois non respectée !"))
{}

DoubleThree::~DoubleThree()
{}

IRule::RuleType	DoubleThree::getRuleType() const
{
  return IRule::DOUBLETHREE;
}

std::string const	&DoubleThree::getError() const
{
  return _lastError;
}

bool		DoubleThree::isCorrect(IGame * game, unsigned int x, unsigned int y, bool color)
{
    vec2 playingPosition =
    {
        static_cast<int>(x),
        static_cast<int>(y)
    };
    _map = game->getMap();
    Case playingCase = _map->getCase(playingPosition.x, playingPosition.y);
    if (color == false)
    {
        _color = false;
        _myCell = Case::BLUE;
    }
    else
    {
        _color = true;
        _myCell = Case::RED;
    }
    _enemyCell = (_myCell == Case::RED) ? Case::BLUE : Case::RED;
    unsigned int axis = 0;
    for (; axis < 8 && !findDoubleThreeByAxis(playingPosition, playingCase, axis);
         ++axis);
    if (axis == 8)
        return true;
    playingCase.setPosable(_color, false);
    return false;
}

bool		DoubleThree::isOk(IGame * game)
{
  vec2 playingPosition =
    {
      static_cast<int>(game->getActivePlayer()->getX()),
      static_cast<int>(game->getActivePlayer()->getY())
    };
  _map = game->getMap();
  Case playingCase = _map->getCase(playingPosition.x, playingPosition.y);  
  if (game->getActivePlayer()->getColor() == IPlayer::BLUE)
    {
      _color = false;
      _myCell = Case::BLUE;
    }
  else
    {
      _color = true;
      _myCell = Case::RED;
    }
  _enemyCell = (_myCell == Case::RED) ? Case::BLUE : Case::RED;
  unsigned int axis = 0;
  for (; axis < 8 && !findDoubleThreeByAxis(playingPosition, playingCase, axis);
       ++axis);
  if (axis == 8)
      return true;
  //playingCase.setPosable(_color, false);
  return false;
}

bool		DoubleThree::findThreeAlignFreeByAxis(vec2 const & playingPosition, Case const & playingCase,
						      unsigned int axis, std::pair<vec2, vec2> & pos) const
{
  if (playingCase.getValue3(static_cast<Case::dir>(axis), Case::YXX, _color))
    pos = { playingPosition -  direction[axis], playingPosition + direction[axis] * 3 };
  else if (playingCase.getValue3(static_cast<Case::dir>(axis), Case::XYX, _color))
    pos = { playingPosition -  direction[axis] * 2, playingPosition + direction[axis] * 2 };
  else if (playingCase.getValue3(static_cast<Case::dir>(axis), Case::YOXX, _color) ||
	   playingCase.getValue3(static_cast<Case::dir>(axis), Case::YXOX, _color))
    pos = { playingPosition -  direction[axis], playingPosition + direction[axis] * 4 };
  else if (playingCase.getValue3(static_cast<Case::dir>(axis), Case::XYOX, _color))
    pos = { playingPosition -  direction[axis] * 2, playingPosition + direction[axis] * 3 };
  else if (playingCase.getValue3(static_cast<Case::dir>(axis), Case::XYOX, _color))
    pos = { playingPosition -  direction[axis] * 2, playingPosition + direction[axis] * 3 };
  else
    return false;
  if ((pos.first.inBound({-1, 19}) && !_map->getCase(pos.first.x, pos.first.y).isEmpty()) ||
      (pos.second.inBound({-1, 19}) && !_map->getCase(pos.second.x, pos.second.y).isEmpty()))
    return false;
    std::cout << "find" << std::endl;
    return true;
}

bool		DoubleThree::findDoubleThreeByAxis(vec2 const & playingPosition, Case const & playingCase, unsigned int axis) const
{
  std::pair<vec2, vec2>	tmp;
  std::pair<vec2, vec2>	pos;
  Case			testCase;

  if (!findThreeAlignFreeByAxis(playingPosition, playingCase, axis, pos))
    return false;
  for (pos.first += direction[axis]; pos.first != pos.second; pos.first += direction[axis])
    {
      for (unsigned int secondAxis = 0; secondAxis < 8; ++secondAxis)
	{
	  if (secondAxis != axis && ((secondAxis + 4)% 8)  != axis &&
	      !(testCase = _map->getCase(pos.first.x, pos.first.y)).isEmpty() &&
	      findThreeAlignFreeByAxis(pos.first, testCase, secondAxis, tmp))
	    return true;
	}
    }
  return false;
}
