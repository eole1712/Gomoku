#ifndef IGAMEMAP_H_
# define IGAMEMAP_H_

class IGameMap
{
public:
  enum		caseContent
    {EMPTY, BLUE, RED};

public:
  virtual ~IGameMap() {}

public:
  virtual void		clear() = 0;
  virtual caseContent	getCase(unsigned int x, unsigned int y) const = 0;
  virtual void		setCase(unsigned int x, unsigned int y, caseContent) = 0;
};

#endif /* !IGAMEMAP_H_ */
