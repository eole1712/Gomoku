#include "Game.hpp"
#include "EatThem.hpp"

EatThem::EatThem()
  : _lastError()
{}

EatThem::~EatThem()
{}

std::string const&	EatThem::getRuleName() const
{
  return ("EatThem");
}

std::string const&	EatThem::getError() const
{
  return (_lastError);
}

bool	EatThem::isOk(Game* game)
{
  caseContent	masterColor = map->getCase(posX, posY);
  int		posX = game.getAction().getX();
  int		posY = game.getAction().getY();

  for (int y = -3; y <= 3; y = y + 3)
    for (int x = -3; x <= 3; x = x + 3)
      if (!game->isOutOfBound(posX + x, posY + y))
	if (map->getCase(posX + x, posY + y) == masterColor)
	  {
	    this->eatBetween(posX, posY, posX + x, posY + y);
	    //TODO ADD 2 POINT TO PLAYER(masterColor);
	  }
}

void EatThem::eatBetween(unsigned int posX, unsigned int posY, unsigned int x, unsigned int y)
{
  eat(x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
  eat(x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));
}

//TODO SET CASE COLOR TO GRAY
void	EatThem::eat(unsigned int posX, unsigned int posY)
{

}
