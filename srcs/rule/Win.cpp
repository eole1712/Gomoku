#include "Win.hpp"

Win::Win()
  : _lastError()
{}

bool			Win::isOk(Game * game)
{
  if (0)
    {

      return false
    }
  return true;
}

std::string const	&Win::getRuleName() const
{
  return std::string("Win");
}

std::string const	&Win::getError() const
{
  return _lastError;
}
