#include "IRule.hpp"
#include "Judge.hpp"

Judge::Judge()
  : _rules(), _lastError("")
{
}

Judge::~Judge()
{}

std::string const	&Judge::getLastError() const
{
  return _lastError;
}

bool			Judge::checkRules(IGame * game)
{
  ruleMap::const_iterator i;

  for (i = _rules.begin();
       i != _rules.end() && (*i).second->isOk(game) && !game->isFinished();
       i++);
  if (i != _rules.end())
    {
      _lastError = (*i).second->getError();
      return false;
    }
  return true;
}

void			Judge::addRule(IRule *rule)
{
  _rules[rule->getRuleType()] = rule;
}

void			Judge::removeRule(IRule::RuleType ruleType)
{
  ruleMap::const_iterator i;

  if ((i = _rules.find(ruleType)) != _rules.end())
    _rules.erase(i);
}
