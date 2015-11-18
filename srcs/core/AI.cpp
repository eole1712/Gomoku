#include "AI.hpp"

AI::AI()
  : _color(BLUE)
{
}

type		AI::getType()
{
  return AI;
}

color		AI::getColor()
{
  return _color;
}
