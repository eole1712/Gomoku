#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <string>
# include "IGame.hpp"
# include "IGameManager.hpp"
# include "IGui.hpp"

class GameManager : public IGameManager
{
public:
  GameManager();
  virtual ~GameManager();

private:
  IGui *	_gui;
  IJudge *	_judge;
  IGame *	_game;

public:
  virtual IJudge *		getJudge() const;
  virtual IGame *		createGame(IGame::mode gameMode = IGame::PVP);
  virtual IGame *		getGame() const;
  virtual IGameMap::caseContent didClickCase(unsigned int x, unsigned y) const;
};

#endif  /* !GAMEMANAGER_HPP_ */
