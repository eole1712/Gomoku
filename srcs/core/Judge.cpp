#include <algorithm>
#include "IRule.hpp"
#include "IGame.hpp"
#include "Judge.hpp"

Judge::Judge()
  : _rules(), _lastError("")
{
}

Judge::~Judge()
{
  std::for_each(_rules.begin(), _rules.end(), [](std::pair<IRule::RuleType, IRule*> rule)
  {
    delete rule.second;
  });
}

std::string const	&Judge::getLastError() const
{
  return _lastError;
}

bool			Judge::checkRules(IGame * game)
{
  ruleMap::const_iterator i;

  if (game->isFinished())
    {
      _lastError = "Game is finished!";
      return false;
    }
  for (i = _rules.begin();
       i != _rules.end() && (*i).second->isOk(game);
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
