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

bool	Win::canEatThis(IGameMap *map,
			int x, int y,
			int Tx, int Ty,
			IGameMap::caseContent v) const
{
  const IGameMap::caseContent	ok[4][5] =
    {
      { IGameMap::EMPTY, IGameMap::EMPTY, IGameMap::RED, IGameMap::RED, IGameMap::BLUE },
      { IGameMap::EMPTY, IGameMap::BLUE, IGameMap::RED, IGameMap::RED, IGameMap::EMPTY },
      { IGameMap::BLUE, IGameMap::RED, IGameMap::RED, IGameMap::EMPTY, IGameMap::EMPTY },
      { IGameMap::EMPTY, IGameMap::RED, IGameMap::RED, IGameMap::BLUE, IGameMap::EMPTY }
    };
  IGameMap::caseContent		cmp[5];
  bool				swap = v != IGameMap::RED;

  int tmp[2] = { x - (2 * Tx), y - (2 * Ty) };
  for (int i = 0; i < 5; i++)
    {
      if (tmp[0] < 0 || tmp[1] < 0 ||
	  tmp[0] > 18 || tmp[0] > 18)
	cmp[i] = IGameMap::BLUE;
      else if (tmp[0] == x && tmp[1] == y)
	cmp[i] = IGameMap::RED;
      else
	{
	  cmp[i] = map->getCase(tmp[0], tmp[1]);
	  if (swap && cmp[i] != IGameMap::EMPTY)
	    cmp[i] = (cmp[i] == IGameMap::RED) ? IGameMap::BLUE : IGameMap::RED;
	}
      tmp[0] += Tx;
      tmp[1] += Ty;
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
  IGameMap::caseContent	v =
    (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? GameMap::BLUE : GameMap::RED;
  IGameMap *	map = game->getMap();
  const char	vecTest[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
  int		x = game->getActivePlayer()->getX();
  int		y = game->getActivePlayer()->getY();
  int		pos[2][2];
  int		i[3];

  game->getMap()->setCase(game->getActivePlayer()->getX(), game->getActivePlayer()->getX(), v);
  if (game->getActivePlayer()->getPoints() > 9)
    {
      game->setWinner();
      return true;
    }
  i[0] = 0;
  for (;i[0] < 4; i[0]++)
    {
      pos[0][0] = x + vecTest[i[0]][0];
      pos[0][1] = y + vecTest[i[0]][1];
      pos[1][0] = x - vecTest[i[0]][0];
      pos[1][1] = y - vecTest[i[0]][1];

      i[1] = 0;
      while (i[1] < 4 &&
	     pos[0][0] < 19 && pos[0][0] >= 0 &&
	     pos[0][1] < 19 && pos[0][1] >= 0 &&
	     map->getCase(pos[0][0], pos[0][1]) == v &&
	     !canEatThis(map, pos[0][0], pos[0][1], vecTest[(i[0] + 1) % 4][0],
			vecTest[(i[0] + 1) % 4][1], v))
	{
	  i[1]++;
	  pos[0][0] += vecTest[i[0]][0];
	  pos[0][1] += vecTest[i[0]][1];
	}
      if (i[1] == 4)
	{
	  game->setWinner();
	  return true;
	}
      i[2] = i[1];
      i[1] = 0;
      while (i[1] < 4 && i[2] < 4 &&
	     pos[1][0] < 19 && pos[1][0] >= 0 &&
	     pos[1][1] < 19 && pos[1][1] >= 0 &&
	     map->getCase(pos[1][0], pos[1][1]) == v &&
	     !canEatThis(map, pos[1][0], pos[1][1], vecTest[(i[0] + 1) % 4][0],
			vecTest[(i[0] + 1) % 4][1], v))
	{
	  i[1]++;
	  i[2]++;
	  pos[1][0] -= vecTest[i[0]][0];
	  pos[1][1] -= vecTest[i[0]][1];
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
