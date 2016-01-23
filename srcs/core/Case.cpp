#include "Case.hpp"

Case::Case()
  : _content(EMPTY), _heuristic(0)
{}

Case::~Case()
{}

Case::caseContent	Case::getContent() const
{
  return (this->_content);
}

char	Case::getHeuristic() const
{
  return (this->_heuristic);
}

void	Case::setContent(Case::caseContent content)
{
  this->_content = content;
}

void	Case::setHeuristic(char heuristic)
{
  this->_heuristic = heuristic;
}
