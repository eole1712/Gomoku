#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <string>
# include "IGameManager.hpp"

class GameManager : public IGameMager
{
public:
  GameManager(mode gameMode = PVE);
  virtual ~GameManager();

private:
  Judge		_judge;
  Game *	_game;

public:

  bool			initJudge();
  Judge *		getJudge() const;
  Game *		createGame();
  Game *		getGame() const;
  IGameMap::caseContent didClickCase(unsigned int x, unsigned y) const;
};

#endif  /* !GAMEMANAGER_HPP_ */
