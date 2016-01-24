#ifndef IGAMEMAP_H_
# define IGAMEMAP_H_

# include "Case.hpp"

class IGameMap
{
public:
  virtual ~IGameMap() {}

public:
  virtual void		clear() = 0;
  virtual Case&		getCase(unsigned int x, unsigned int y) = 0;
  virtual void		setCase(unsigned int x, unsigned int y, Case::caseContent) = 0;
  virtual bool		isIn(unsigned int x, unsigned int y) const = 0;
};

#endif /* !IGAMEMAP_H_ */
