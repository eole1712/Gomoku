#ifndef GAMEMAP_HPP_
# define GAMEMAP_HPP_

# include "IGameMap.hpp"
# include "Case.hpp"

class GameMap
  : public IGameMap
{
public:
  static const unsigned int	size_x = 19;
  static const unsigned int	size_y = 19;

public:
  GameMap();
  virtual ~GameMap();

private:
  Case	_map[size_x][size_y];

public:
  virtual void		clear();
  virtual Case&		getCase(unsigned int x, unsigned int y);
  virtual void		setCase(unsigned int x, unsigned int y, Case::caseContent);
  virtual bool		isIn(unsigned int x, unsigned int y) const;
};

#endif /* !GAMEMAP_HPP_ */
