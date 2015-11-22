#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "DoubleThree.hpp"

DoubleThree::DoubleThree()
  : _lastError()
{}

DoubleThree::~DoubleThree()
{}

IRule::RuleType	DoubleThree::getRuleType() const
{
  return IRule::BASICCHECK;
}

std::string const	&DoubleThree::getError() const
{
  return _lastError;
}

bool		DoubleThree::isOk(IGame * game)
{
  GameMap::caseContent	v =
    (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? GameMap::BLUE : GameMap::RED;
  IGameMap *	map = game->getMap();
  char		vecTest[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
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
      if ((x < 18 && y < 18 && x > 0 && y > 0) &&
	  map->getCase(pos[0][0], pos[0][1]) == v &&
	  map->getCase(pos[1][0], pos[1][1]) == v)
	{
	  count++;
	  if (count == 2)
	    return false;
	}
      i[1] = 0;
      i[2] = 0;
      while (i[1] < 3 && i[2] < 2 &&
	      (pos[0][0] += vecTest[i[0]][0]) < 19 && pos[0][0] >= 0 &&
	      (pos[0][1] += vecTest[i[0]][1]) < 19 && pos[0][1] >= 0)
	{
	  i[2] += (map->getCase(pos[0][0], pos[0][1]) == v);
	  i[1]++;
	}
      if (i[2] == 2)
	{
	  count++;
	  if (count == 2)
	    return false;
	}
      i[1] = 0;
      i[2] = 0;
      while (i[1] < 3 && i[2] < 2 &&
	      (pos[1][0] -= vecTest[i[0]][0]) < 19 && pos[1][0] >= 0 &&
	      (pos[1][1] -= vecTest[i[0]][1]) < 19 && pos[1][1] >= 0)
	{
	  i[2] += (map->getCase(pos[1][0], pos[1][1]) == v);
	  i[1]++;
	}
      if (i[2] == 2)
	  count++;
    }
  return (count > 1);
}
