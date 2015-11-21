#ifndef GAMEMAP_HPP_
# define GAMEMAP_HPP_

#include "IGameMap.hpp"

class GameMap
  : public IGameMap
{
public:
  static const unsigned int	size_x = 19;
  static const unsigned int	size_y = 19;

public:
  GameMap();
  virtual ~GameMap() {}

private:
  caseContent	_map[size_x][size_y];

public:
  virtual void		clear();
  virtual caseContent	getCase(unsigned int x, unsigned int y) const;
  virtual void		setCase(unsigned int x, unsigned int y, caseContent);
  virtual bool		isIn(unsigned int x, unsigned int y) const;
};

#endif /* !GAMEMAP_HPP_ */
