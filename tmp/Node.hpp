#ifndef NODE_H_
# define NODE_H_

#include <list>
#include "TmpMap.hpp"

class Node
{
public:
  typedef TmpMap MapType;
  Node(mapType const& map, std::pair<int, int> move, Node* parent = nullptr, bool isMax = true);
  virtual ~Node();
  int getNote();
  std::pair<int, int> const& getMove();
  bool isMax();
  std::list<Node> const& getChildren();
  void addChild(Node & child);
  bool operator==(Node const& node);
  int evaluate(int depth, int min, int max);
  void initialize(int depth);
  constexpr int loose = -100;
  constexpr int win = 100;
private:
  int _note;
  Node *_parent;
  bool _isMax;
  std::list<Node> _childrens;
  std::pair<int, int> _move;
  mapType _map;
};

#endif /* !NODE_H_ */
