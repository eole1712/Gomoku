#ifndef GAMEMAP_HPP_
# define GAMEMAP_HPP_

#include "IGameMap.hpp"

class GameMap
  : public IGameMap
{
public:
  GameMap();
  virtual ~GameMap() {}

private:
  caseContent	_map[19][19];

public:
  virtual void		clear();
  virtual caseContent	getCase(unsigned int x, unsigned int y) const;
  virtual void		setCase(unsigned int x, unsigned int y, caseContent);
  virtual bool		isIn(unsigned int x, unsigned int y) const;
};

#endif /* !GAMEMAP_HPP_ */
