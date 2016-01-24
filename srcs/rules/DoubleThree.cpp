#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "DoubleThree.hpp"

#include <iostream>

DoubleThree::DoubleThree()
  : _lastError(std::string("Regle des trois non respectée !")),
    _axis{{1, 0}, {0, 1}, {1, 1}, {-1, 1}}, _boundLimit{-1, 19},
    _validCase
    {
      { Case::EMPTY, Case::RED, Case::RED, Case::RED, Case::EMPTY},
      { Case::EMPTY, Case::RED, Case::EMPTY, Case::RED, Case::RED},
      { Case::EMPTY, Case::RED, Case::RED, Case::EMPTY, Case::RED},
      { Case::RED, Case::RED, Case::EMPTY, Case::RED, Case::EMPTY},
      { Case::RED, Case::EMPTY, Case::RED, Case::RED, Case::EMPTY}
    }
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

bool		DoubleThree::isOk(IGame * game)
{
  align		tmp[5];
  _myCell = (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? Case::BLUE : Case::RED;
  _enemyCell = (_myCell == Case::RED) ? Case::BLUE : Case::RED;
  _playingPosition =
    {
      static_cast<int>(game->getActivePlayer()->getX()),
      static_cast<int>(game->getActivePlayer()->getY())
    };
  _map = game->getMap();
  int i = 0;
  std::cout << "--------------------------------" << std::endl;
  for (; i < 4 && !(checkFreeAlign(_playingPosition, _axis[i], &tmp[0])
		    && haveSecondAlign(i, &tmp[0])); i++);
  return i == 4;
}

bool		DoubleThree::checkFreeAlign(vec2 const & origin, vec2 axis, align * alignOut)
{
  std::pair<Case::caseContent, vec2>* alignPtr;
  std::pair<Case::caseContent, vec2>	alignement[13];
  Case::caseContent			cell;
  vec2		pos;
  bool		swap = _myCell == Case::BLUE;
  bool		lastCellEmpty = false;
  char		emptyCellFind = 0;
  char		alignDirection = 1;

  alignPtr = &alignement[5];
  for (int i = 0; i < 13; i++)
    alignement[i] = { Case::BLUE, 0 };
  alignement[4] = { Case::RED, origin };
  for (unsigned char j = 0; j < 2; ++j)
    {
      pos = origin + axis;
      for (unsigned char i = 0; i < 4 && pos.inBound(_boundLimit) &&
	     (cell = _map->getCase(pos.x, pos.y).getContent()) != _enemyCell &&
	     !(cell == Case::EMPTY && (lastCellEmpty || emptyCellFind == 2)); ++i)
	{
	  alignPtr[0].first = cell;
	  alignPtr[0].second = pos;
	  if (alignPtr[0].first == Case::EMPTY)
	    {
	      lastCellEmpty = true;
	      emptyCellFind++;
	    }
	  else
	    {
	      lastCellEmpty = false;
	      if (swap)
		alignPtr[0].first = Case::RED;
	    }
	  alignPtr += alignDirection;
	  pos += axis;
	}
      if (!j)
	{
	  lastCellEmpty = false;
	  if (emptyCellFind == 2)
	    --emptyCellFind;
	  axis = -axis;
	  alignPtr = &alignement[3];
	  alignDirection = -1;
	}
    }
  alignPtr = &alignement[0];
  while (alignPtr[0].first == Case::BLUE && alignPtr != &alignement[8])
    ++alignPtr;
  if (((&alignement[8]) - alignPtr) < 5) // 2 Empty + 3 prise
    return false;
  for (unsigned char i = 0; i < 5; i++)
    {
      unsigned char j = 0;
      for (; j < 5 && alignPtr[j].first == _validCase[i][j]; j++);
      if (j == 5)
	{
	  for (unsigned char k = 0; k < 5; ++k)
	    alignOut[k] = alignPtr[k];
	  return true;
	}
    }
  return false;
}

bool		DoubleThree::haveSecondAlign(int const & originAxis, align * alignPtr)
{
  align		tmp[5];
  for (int j = 0; j < 5; j++)
    {
      for (int i = 0; i < 4; i++)
	{
	  if (i != originAxis && alignPtr[j].first == Case::RED &&
	      checkFreeAlign(alignPtr[j].second, _axis[i], &tmp[0]))
	    return true;
	}
    }
  return false;
}
