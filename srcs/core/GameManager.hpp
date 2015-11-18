#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <string>
# include "IPlayer.hpp"
# include "GameMap.hpp"
# include "Judge.hpp"

class GameManager
{
public:
  GameManager(mode gameMode = PVE);
  virtual ~GameManager() {}

private:
  mode		_mode;
  Judge		_judge;
  Game *	_game;

protected:
  bool			initJudge();
  void			initPlayer();

public:

  IGame *		createGame();
  void			setMode(mode);
  mode			getMode() const;
  Game *		getGame() const;
  IGameMap::caseContent didClickCase(unsigned int x, unsigned y);
};

#endif  /* !GAMEMANAGER_HPP_ */