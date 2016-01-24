#ifndef MINMAX_H_
# define MINMAX_H_

#include "Node.hpp"

class MinMax
{
public:
  MinMax(Node::MapType& map);
  virtual ~MinMax();
  std::pair<int, int> evaluate(int depth);
  void initialize(int depth);
  void setFirst(Node* node);
private:
  Node* m_current;

};

#endif /* !MINMAX_H_ */
