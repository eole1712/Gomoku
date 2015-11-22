#include "Game.hpp"
#include "GameMap.hpp"
#include "IRule.hpp"
#include "Win.hpp"

Win::Win()
  : _lastError()
{}

Win::~Win()
{}

bool	Win::canEatThis(IGameMap *,
			unsigned int , unsigned int ,
			unsigned int , unsigned int ,
			IGameMap::caseContent , IGameMap::caseContent) const
{
  /*
  if (map.isIn(x - vecTX, y - vecTY) &&
      map.getCase(x - vecTX, y - vecTY) != ) );
*/
  return false;
}

bool	Win::isOk(IGame* game)
{
  IGameMap::caseContent	v =
    (game->getActivePlayer()->getColor() == IPlayer::BLUE) ? GameMap::BLUE : GameMap::RED;
  GameMap::caseContent	nope = (v == GameMap::BLUE) ? GameMap::RED : GameMap::BLUE;
  IGameMap *	map = game->getMap();
  char		vecTest[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
  int		x = game->getActivePlayer()->getX();
  int		y = game->getActivePlayer()->getY();
  int		pos[2][2];
  int		i[3];

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
      while (i[1] < 5 &&
	     pos[0][0] < 19 && pos[0][0] >= 0 &&
	     pos[0][1] < 19 && pos[0][1] >= 0 &&
	     map->getCase(pos[0][0], pos[0][1]) == v &&
	     canEatThis(map, pos[0][0], pos[0][1], vecTest[i[0]][0], vecTest[i[0]][1], v, nope))
	{
	  i[1]++;
	  pos[0][0] += vecTest[i[0]][0];
	  pos[0][1] += vecTest[i[0]][1];
	}
      if (i[1] == 5)
	{
	  game->setWinner();
	  return true;
	}
      i[2] = i[1];
      i[1] = 0;
      while (i[1] < 5 && i[2] < 5 &&
	     pos[1][0] < 19 && pos[1][0] >= 0 &&
	     pos[1][1] < 19 && pos[1][1] >= 0 &&
	     map->getCase(pos[1][0], pos[1][1]) == v &&
	     canEatThis(map, pos[0][0], pos[0][1], vecTest[i[0]][0], vecTest[i[0]][1], v, nope))
	{
	  i[1]++;
	  pos[1][0] += vecTest[i[0]][0];
	  pos[1][1] += vecTest[i[0]][1];
	}
      if (i[2] == 5)
	{
	  game->setWinner();
	  return true;
	}
    }
  return false;
}

IRule::RuleType	Win::getRuleType() const
{
  return (IRule::WIN);
}

std::string const&	Win::getError() const
{
  return (this->_lastError);
}
