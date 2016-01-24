#include "Node.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

int Node::_maxDepth = -1;

Node::Node(MapType& map, std::pair<int, int> move, Node* parent, bool isMax)
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
    int tmpNote = 0;

    if (_maxDepth == -1)
        _maxDepth = depth;
    if (_parent)
        tmpNote = _parent->_eval;
    _eval = tmpNote + _map.evaluate(_move, _isMax);
    _note = _eval;
    _map.setCase(_move.first, _move.second, static_cast<Case::caseContent>(_isMax));
    if (_eval != 0)
        std::cout << _eval;

    if (_note == win || _note == loose || depth == 0)
        return _note;
    if (_childrens.empty())
    {
        initialize(depth);
    }
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
  std::list<GameMap::noteType> moves;

  if (_isMax) {
    moves = _map.getMaxMoves();
  }
  else {
      moves = _map.getMinMoves();
  }

  for (auto& move : moves)
    {
      //std::cout << "note : " << std::get<0>(move) << ", " << std::get<1>(move) << ", " << std::get<2>(move) <<  std::endl;
      _childrens.push_back(new Node(_map, std::make_pair(std::get<1>(move), std::get<2>(move)), this, !_isMax));
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
