#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "IPlayer.hpp"
#include "DoubleThree.hpp"

DoubleThree::DoubleThree()
  : _lastError(std::string("Regle des trois non respecté !"))
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
  GameMap::caseContent	v =
    (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? GameMap::BLUE : GameMap::RED;
  GameMap::caseContent	nope = (v == GameMap::BLUE) ? GameMap::RED : GameMap::BLUE;
  IGameMap *	map = game->getMap();
  const char	vecTest[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
  int		x = game->getActivePlayer()->getX();
  int		y = game->getActivePlayer()->getY();
  int		pos[2][2];
  char		count = 0;
  int		i[3];

  i[0] = 0;
  for (;i[0] < 4 && count < 2; i[0]++)
    {
      pos[0][0] = x + vecTest[i[0]][0];
      pos[0][1] = y + vecTest[i[0]][1];
      pos[1][0] = x - vecTest[i[0]][0];
      pos[1][1] = y - vecTest[i[0]][1];
      i[1] = 0;
      i[2] = 0;
      while (i[1] < 4 && i[2] < 2 &&
	     pos[0][0] < 19 && pos[0][0] >= 0 &&
	     pos[0][1] < 19 && pos[0][1] >= 0 &&
	     map->getCase(pos[0][0], pos[0][1]) != nope)
	{
	  i[2] += (map->getCase(pos[0][0], pos[0][1]) == v);
	  i[1]++;
	  pos[0][0] += vecTest[i[0]][0];
	  pos[0][1] += vecTest[i[0]][1];
	}
      if (i[2] == 2 &&
	  pos[0][0] < 19 && pos[0][0] >= 0 &&
	  pos[0][1] < 19 && pos[0][1] >= 0 &&
	  map->getCase(pos[0][0], pos[0][1]) == GameMap::EMPTY &&
	  pos[1][0] < 19 && pos[1][0] >= 0 &&
	  pos[1][1] < 19 && pos[1][1] >= 0 &&
	  map->getCase(pos[1][0], pos[1][1]) == GameMap::EMPTY)
	{
	  count++;
	  if (count == 2)
              return false;
	}
      i[1] = 0;
      i[2] = 0;
      while (i[1] < 4 && i[2] < 2 &&
	      pos[1][0] < 19 && pos[1][0] >= 0 &&
	      pos[1][1] < 19 && pos[1][1] >= 0 &&
	     map->getCase(pos[1][0], pos[1][1]) != nope)
	{
	  i[2] += (map->getCase(pos[1][0], pos[1][1]) == v);
	  i[1]++;
	  pos[1][0] -= vecTest[i[0]][0];
	  pos[1][1] -= vecTest[i[0]][1];
	}
	if (i[2] == 2)
	  {
	    int tmp[2] = {x + (2 * vecTest[i[0]][0]), y + (2 * vecTest[i[0]][1])};
	    if (((pos[0][0] < 19 && pos[0][0] >= 0 &&
		  pos[0][1] < 19 && pos[0][1] >= 0 &&
		  map->getCase(pos[0][0], pos[0][1]) == GameMap::EMPTY) ||
		 (tmp[0] < 19 && tmp[0] >= 0 &&
		  tmp[1] < 19 && tmp[1] >= 0 &&
		  map->getCase(tmp[0], tmp[1]) == GameMap::EMPTY)) &&
		pos[1][0] < 19 && pos[1][0] >= 0 &&
		pos[1][1] < 19 && pos[1][1] >= 0 &&
		map->getCase(pos[1][0], pos[1][1]) == GameMap::EMPTY)
		count++;
	  }
    }
  return (count < 2);
}
