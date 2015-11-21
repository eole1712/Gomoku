#include "Win.hpp"

Win::Win()
  : _lastError()
{}

Win::~Win()
{}

bool	Win::isOk(IGame* game)
{
  int		posX = game->getActivePlayer()->getX();
  int		posY = game->getActivePlayer()->getY();
  IGameMap*	map = game->getMap();
  bool		returnValue = false;

  // conditions de win à gérer :
  // - check 5 alignés horizontalement
  // et pas de cas 1, 2, 3 ou 4 :
  // X   E
  // O E O X
  // O O O O O (<--- ligne horizontale)
  // E O X O
  //   X   E
  // 1 2 3 4   (<--- cas)
  // ||
  // - check 5 alignés verticalement
  // et pas de : pareil qu'horizontal mais à la verticale
  return (returnValue);
}

IRule::RuleType	Win::getRuleType() const
{
  return (IRule::WIN);
}

std::string const&	Win::getError() const
{
  return (this->_lastError);
}
