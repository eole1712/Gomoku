#include "Case.hpp"

Case::Case()
  : _content(EMPTY)
{}

Case::~Case()
{}

Case::caseContent	Case::getCaseContent()
{
  return (_content);
}

void	Case::setCaseContent(Case::caseContent content)
{
  this->_content = content;
}
