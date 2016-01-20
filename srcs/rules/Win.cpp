#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "Win.hpp"

Win::Win()
  : _lastError("Win error")
{}

Win::~Win()
{}

bool	Win::canEatThis(IGameMap *map, vec2 origin, vec2 axis,
			Case::caseContent v) const
{
  const Case::caseContent	ok[4][5] =
    {
      { Case::EMPTY, Case::EMPTY, Case::RED, Case::RED, Case::BLUE },
      { Case::EMPTY, Case::BLUE, Case::RED, Case::RED, Case::EMPTY },
      { Case::BLUE, Case::RED, Case::RED, Case::EMPTY, Case::EMPTY },
      { Case::EMPTY, Case::RED, Case::RED, Case::BLUE, Case::EMPTY }
    };
  Case::caseContent		cmp[5];
  bool				swap = v != Case::RED;

  vec2 tmp = { origin.x - (2 * axis.x), origin.y - (2 * axis.y) };
  for (int i = 0; i < 5; i++)
    {
      if (!tmp.inBound({-1, 19}))
	cmp[i] = Case::BLUE;
      else if (tmp == origin)
	cmp[i] = Case::RED;
      else
	{
	  cmp[i] = map->getCase(tmp[0], tmp[1])->getCaseContent();
	  if (swap && cmp[i] != Case::EMPTY)
	    cmp[i] = (cmp[i] == Case::RED) ? Case::BLUE : Case::RED;
	}
      tmp += axis;
    }
  for (int i = 0; i < 4; i++)
    {
      int j = 0;
      for (; j < 5 && cmp[j] == ok[i][j]; j++);
      if (j == 5)
	return true;
    }
  return false;
}

bool	Win::isOk(IGame* game)
{
  Case::caseContent	v =
    (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? Case::BLUE : Case::RED;
  IGameMap *	map = game->getMap();
  const vec2	axis[4] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
  const vec2	normal[4] = {{0, 1}, {1, 0}, {-1, 1}, {1, 1}};
  vec2		pos[2];
  int		i[3];
  vec2		origin =
    {
      static_cast<int>(game->getActivePlayer()->getX()),
      static_cast<int>(game->getActivePlayer()->getY())
    };

  if (game->getActivePlayer()->getPoints() > 9)
    {
      game->setWinner();
      return true;
    }
  i[0] = 0;
  for (;i[0] < 4; ++i[0])
    {
      pos[0] = origin + axis[i[0]];
      pos[1] = origin - axis[i[0]];
      i[1] = 0;
      while (i[1] < 4 &&
	     pos[0].inBound({-1, 19}) &&
	     map->getCase(pos[0].x, pos[0].y)->getCaseContent() == v &&
	     !canEatThis(map, pos[0], normal[i[0]], v))
	{
	  i[1]++;
	  pos[0] += axis[i[0]];
	}
      if (i[1] == 4)
	{
	  game->setWinner();
	  return true;
	}
      i[2] = i[1];
      i[1] = 0;
      while (i[1] < 4 && i[2] < 4 &&
	     pos[1].inBound({-1, 19}) &&
	     map->getCase(pos[1][0], pos[1][1])->getCaseContent() == v &&
	     !canEatThis(map, pos[1], normal[i[0]], v))
	{
	  i[1]++;
	  i[2]++;
	  pos[1] -= axis[i[0]];
	}
      if (i[2] == 4)
	{
	  game->setWinner();
	  return true;
	}
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
