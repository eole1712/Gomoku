#ifndef NODE_H_
# define NODE_H_

#include <list>
#include <ctime>
#include <cstring>
#include <random>
#include <iostream>

#include "GameMap.hpp"

class TmpMap {
public:
    TmpMap()
    {

    }

    TmpMap(TmpMap const& o)
    {
        std::memcpy(tab, o.tab, sizeof(o.tab));
    }

    int evaluate()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(-99, 99);
        return dis(gen);
    }

    std::list<std::pair<int, int> > getMoves()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 19);
        int i  = 0;
        std::list<std::pair<int, int> > l;

        while (i < 10)
        {
            l.emplace_back(dis(gen), dis(gen));
            ++i;
        }
        return l;
    }
private:
    uint64_t tab[6][19][19];
};

class Node
{
public:
  typedef GameMap MapType;
  Node(MapType & map, std::pair<int, int> move, Node* parent = nullptr, bool isMax = true);
  virtual ~Node();
  void deleteExcept(std::pair<int, int> const& value, bool check);
  int getNote();
  std::pair<int, int> const& getMove();
  bool isMax();
  std::list<Node*> const& getChildren();
  void addChild(Node* child);
  bool operator==(Node const& node);
  int evaluate(int depth, int min, int max);
  void initialize(int depth);
  void deleteUnused(int depth);
  static constexpr int loose = -25000;
  static constexpr int win = 25000;
  void print(std::ostream &file);
private:
  MapType _map;
  std::pair<int, int> _move;
  Node *_parent;
  bool _isMax;
  int _note;
  int _eval = -1;
  std::list<Node*> _childrens;
  static int _maxDepth;
};

#endif /* !NODE_H_ */
