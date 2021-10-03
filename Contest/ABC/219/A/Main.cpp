#include <iostream>

int main()
{
  int x;
  std::cin >> x;
  
  if (x >= 90)
  {
    std::cout << "expert" << std::endl;
  }
  else if (x >= 70)
  {
    std::cout << (90 - x) << std::endl;
  }
  else if (x >= 40)
  {
    std::cout << (70 - x) << std::endl;
  }
  else
  {
    std::cout << (40 - x) << std::endl;
  }
  return 0;
}
