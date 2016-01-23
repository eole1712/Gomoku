#include "Node.hpp"

Node::Node(Node* parent, bool isMax)
  : _parent(parent),
    _isMax(isMax)
{
  ;
}

int Node::getNote()
{
  return _note;
}

std::pair<int, int> const& Node::getMove()
{
  return _move;
}

bool Node::isMax()
{
  return _isMax;
}

std::list<Node> const& Node::getChildren()
{
  return _childrens;
}

void Node::addChild(Node &child)
{
  _childrens.push_back(child);
}

bool Node::operator==(Node const& node)
{
  return node._parent == _parent && node._move == _move;
}

void Node::evaluate(int depth, int min, int max)
{
  int tmpNote;
  _note = map.getNote(_move.first, _move.second);
  if (_note == win || _note === loose || depth == 0)
    return _note;
  if (_childrens.empty())
    {
      initialize(depth);
    }
  if (_isMax)
    {
      _note = min;
      for (auto& child : _childrens) {
	tmpNote = evaluate(depth - 1, _note, max);
	if (tmpNote > _note)
	  _note = tmpNote;
	if (_note > max)
	  {
	    _note = max;
	    return max;
	  }
      }
      return _note;
    }
  else
    {
      _note = min;
      for (auto& child : _childrens) {
	tmpNote = evaluate(depth - 1, min, _note);
	if (tmpNote < _note)
	  _note = tmpNote;
	if (_note < min) {
	  _note = min;
	  return min;
	}
      }
      return _note;
    }
}

void Node::initialize(int depth)
{
  std::list<std::pair<int, int> > moves;

  moves = _map.getMoves();
  for (auto& move : moves)
    {
      _childrens.emplace_back(_map, move, this, !_isMax);
      _childrens.back().initialize(depth - 1);
    }
}
