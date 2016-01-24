#include "MinMax.hpp"
#include "Node.hpp"

#include <iostream>

int main()
{
  TmpMap map;
  MinMax m(map);

  std::pair<int, int> res = m.evaluate(5);
  std::cout << "x : " << res.first << ", y :" << res.second << std::endl;
}
