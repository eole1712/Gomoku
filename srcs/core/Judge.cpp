#include "Judge.hpp"

Judge::Judge()
  : _rules(), _lastError("")
{
}

std::string const	&getLastError() const
{
  return _lastError;
}

bool			Judge::checkRules()
{
  ruleMap::const_iterator i;

  for (i = _rules.begin(); i != _rules.end() && (*i).isOk(); i++);
  if (i != _rules.end())
    {
      _lastError = (*i).getError();
      return false;
    }
  return true;
}

void			Judge::addRule(IRule *rule)
{
  _rules[rule.getRuleName()] = rule;
}

bool			Judge::removeRule(std::string const &ruleName)
{
  ruleMap::const_iterator i;

  if ((i = _rules.find(ruleName)) != _rules.end())
    _rules.erase(i);
}
