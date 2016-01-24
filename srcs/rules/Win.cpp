#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "DoubleThree.hpp"
#include "Win.hpp"

#include <iostream>

Win::Win()
  : _lastError("Win error")
{}

Win::~Win()
{}

bool	Win::canEatThis(IGameMap *map, vec2 playingPosition, Case testCase,
			int axis, bool color) const
{
  if (testCase.getValue2(static_cast<Case::dir>(axis), Case::YX, color))
    {
      vec2 pos[2] = { playingPosition - direction[axis], playingPosition + direction[axis] * 2 };
      if ((pos[0].inBound({-1, 19}) && map->getCase(pos[0].x, pos[0].y).getColor() != color) !=
	  (pos[1].inBound({-1, 19}) && map->getCase(pos[1].x, pos[1].y).getColor() != color))
	return true;
    }
  return false;
}

bool	Win::isOk(IGame* game)
{
  vec2			pos;
  Case			testCase;
  IGameMap *	map = game->getMap();
  vec2		playingPosition =
    {
      static_cast<int>(game->getActivePlayer()->getX()),
      static_cast<int>(game->getActivePlayer()->getY())
    };
  Case		playingCase = map->getCase(playingPosition.x, playingPosition.y);
  bool		color = playingCase.getColor();

  if (game->getActivePlayer()->getPoints() > 9)
    {
      game->setWinner();
      return true;
    }
  
  for (int axis = 0; axis < 8; ++axis)
    {
      if (playingCase.getValue5(static_cast<Case::dir>(axis), Case::YXXXX, color))
	pos = playingPosition;
      else if (playingCase.getValue5(static_cast<Case::dir>(axis), Case::XYXXX, color))
	pos = playingPosition - direction[axis];
      else if (axis < 4 && playingCase.getValue5(static_cast<Case::dir>(axis), Case::XXYXX, color))
	pos = playingPosition - direction[axis] * 2;
      else
	continue;
      std::cout << "color" << color << std::endl;
      for (int i = 0; i < 5; ++i) 
	{
	  testCase = map->getCase(pos.x, pos.y);
	  for (int secondAxis = 0; secondAxis < 8; ++secondAxis)
	    {
	      if (secondAxis != axis && secondAxis != ((axis + 4) % 8) &&
		  canEatThis(map, pos, testCase, secondAxis, color))
		return true;
	    }
	  pos += direction[axis];
	}
      game->setWinner();
    }
  return true;
}

IRule::RuleType	Win::getRuleType() const
{
  return (IRule::WIN);
}

std::string const&	Win::getError() const
{
  return (this->_lastError);
}
