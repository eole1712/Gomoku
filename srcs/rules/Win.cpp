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
  // et pas de haut = ennemi && (bas == ennemi || bas = empty) (ou inverse) sur chacune des 5
  // ||
  // - check 5 alignés verticalement
  // et pas de gauche = ennemi && (droite == ennemi || droite = empty) (ou inverse) sur chacune des 5
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
