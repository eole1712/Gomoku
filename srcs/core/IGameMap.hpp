#ifndef IGAMEMAP_H_
# define IGAMEMAP_H_

# include <string>

class IGameMap
{
public:
  enum		CaseContent
    {EMPTY, BLUE, RED};

public:
  virtual ~IGameMap() {}

public:
  virtual void		clear() = 0;
  virtual CaseContent	getCase(unsigned int x, unsigned int y) const = 0;
  virtual void		setCase(unsigned int x, unsigned int y, CaseContent) = 0;
};

#endif /* !IGAMEMAP_H_ */
