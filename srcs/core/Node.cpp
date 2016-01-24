#include "Node.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

int Node::_maxDepth = -1;

Node::Node(MapType const& map, std::pair<int, int> move, Node* parent, bool isMax)
  : _map(map),
    _move(move),
    _parent(parent),
    _isMax(isMax),
    _note(-1)
{
  ;
}

Node::~Node()
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

std::list<Node*> const& Node::getChildren()
{
  return _childrens;
}

void Node::addChild(Node *child)
{
  _childrens.push_back(child);
}

bool Node::operator==(Node const& node)
{
  return node._parent == _parent && node._move == _move;
}

int Node::evaluate(int depth, int min, int max)
{
    int tmpNote;

    if (_maxDepth == -1)
        _maxDepth = depth;
    _note = _map.evaluate();
    if (_note == win || _note == loose || depth == 0)
        return _note;
    initialize(depth);
    if (_isMax)
    {
        _note = min;
        for (auto& child : _childrens) {
            tmpNote = child->evaluate(depth - 1, _note, max);
            if (tmpNote > _note)
                _note = tmpNote;
            else if (depth != _maxDepth - 1) {
                delete child;
                child = nullptr;
            }
            if (_note > max)
            {
                _note = max;
                deleteUnused(depth);
                return max;
            }
        }
        deleteUnused(depth);
        return _note;
    }
    else
    {
        _note = max;
        for (auto& child : _childrens) {
            tmpNote = child->evaluate(depth - 1, min, _note);
            if (tmpNote < _note) {
                _note = tmpNote;
            }
            else if (depth != _maxDepth - 1) {
                delete child;
                child = nullptr;
            }
            if (_note < min) {
                _note = min;
                deleteUnused(depth);
                return min;
            }
        }
        deleteUnused(depth);
        return _note;
    }
}

void Node::initialize(int depth)
{
  std::list<std::pair<int, int> > moves;

  moves = _map.getMoves();
  for (auto& move : moves)
    {
      _childrens.push_back(new Node(_map, move, this, !_isMax));
  }
}

void Node::deleteUnused(int depth)
{
    if (depth == _maxDepth - 1)
        return;
    for (auto& child : _childrens)
    {
        if (child && child->getNote() != _note)
        {
            delete child;
            child = nullptr;
        }
    }
    _childrens.erase(std::remove(_childrens.begin(), _childrens.end(), nullptr), _childrens.end());
}

void Node::deleteExcept(std::pair<int, int> const& value, bool check)
{
    for (auto& child : _childrens)
    {
        if (!check || value != child->getMove())
        {
            child->deleteExcept(value, false);
            delete child;
        }
    }

}

void Node::print(std::ostream& file)
{
    file << (long)this << " [label=" << _note << "];" << std::endl;
    for (auto& child : _childrens) {
        std::pair<int, int > move = child->getMove();
        file << std::setbase(10) << (long)this << " -> " << (long)child << " [label=" << move.first << move.second << "];" << std::endl;
        child->print(file);
    }
}
