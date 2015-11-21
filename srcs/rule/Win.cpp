#include "Win.hpp"

Win::Win()
  : _lastError()
{}

Win::~Win()
{}

bool	Win::isOk(Game*)// game)
{
  // conditions de win à gérer
  if (0)
    {

      return (false);
    }
  return (true);
}

IRule::RuleType	Win::getRuleType() const
{
  return (IRule::WIN);
}

std::string const&	Win::getError() const
{
  return (this->_lastError);
}
