#include "Case.hpp"

Case::Case()
  : _content(EMPTY)
{
  this->_heuristic[0] = 0;
  this->_heuristic[1] = 0;
}

Case::~Case()
{}

Case::caseContent	Case::getContent() const
{
  return (this->_content);
}

char	Case::getHeuristic(unsigned int numPlayer) const
{
  if (numPlayer > 1)
    return (0);
  return (this->_heuristic[numPlayer]);
}

void	Case::setContent(Case::caseContent content)
{
  this->_content = content;
  if (content != caseContent::EMPTY)
    {
      this->_heuristic[0] = 0;
      this->_heuristic[1] = 0;
    }
}

void	Case::setHeuristic(unsigned int numPlayer, char heuristic)
{
  if (numPlayer > 1)
    return;
  this->_heuristic[numPlayer] = heuristic;
}
