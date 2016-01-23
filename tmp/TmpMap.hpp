#ifndef TMPMAP_H_
# define TMPMAP_H_

#include <list>
#include <pair>
#include "ICase.hpp"

class TmpMap
{
public:
  TmpMap();
  virtual ~TmpMap();
  std::list<std::pair<int, int> > getMoves();
  int getNote(int x, int y);
private:
  ICase* _map[19][19];
};

#endif /* !TMPMAP_H_ */
