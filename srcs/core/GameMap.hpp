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
  void		clear();
  caseContent	getCase(unsigned int x, unsigned int y) const;
  void		setCase(unsigned int x, unsigned int y, caseContent);
};

#endif /* !GAMEMAP_HPP_ */
