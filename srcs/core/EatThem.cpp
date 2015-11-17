#include "IGameMap.hpp"

int 	eatThem(IGameMap* map, unsigned int posX, unsigned int posY)
{
	caseContent masterColor = map->getCase(posX, posY);
	for (int y = -3; y <= 3; y = y + 3)
	{
		for (int x = -3; x <= 3; x = x + 3)
		{
			if (!isOutOfBound(posX + x, posY + y))
			{
				if (map->getCase(posX + x, posY + y) == masterColor)
				{
					eatBetween(posX, posY, posX + x, posY + y);
					//TODO ADD 2 POINT TO PLAYER(masterColor);
				}
			}
		}
	}
}

void eatBetween(unsigned int posX, unsigned int posY, unsigned int x, unsigned int y)
{
	eat(x + (posX > x) - (posX < x), y + (posY > y) - (posY < y));
	eat(x + 2 * ((posX > x) - (posX < x)), y + 2 * ((posY > y) - (posY < y)));
}

//TODO SET CASE COLOR TO GRAY
void eat(unsigned int posX, unsigned int posY)
{

}

//TODO REPLACE 18 WITH DEFINE OR CONST VALUES;
bool 	isOutOfBound(int x, int y)
{
	return (x < 0 || x > 18 || y < 0 || y > 18);
}