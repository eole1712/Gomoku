#include "Humain.hpp"

Humain::Humain()
  : _color(BLUE)
{
}

type		Humain::getType()
{
  return HUMAIN;
}

color		Humain::getColor()
{
  return _color;
}
