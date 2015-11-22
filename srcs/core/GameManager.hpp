#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <string>
# include "IGameManager.hpp"

class IGui;
class IJudge;
class IGame;

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
  virtual void			start() const;
  virtual IGame *		createGame(IGame::mode gameMode = IGame::PVP);
  virtual IGame *		getGame() const;
  virtual void didClickCase(unsigned int x, unsigned y);
  virtual void		removeGame();
};

#endif  /* !GAMEMANAGER_HPP_ */
