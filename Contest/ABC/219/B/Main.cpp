#include <iostream>
#include <string>

int main()
{
  std::string s1, s2, s3, t;
  std::cin >> s1 >> s2 >> s3 >> t;

  /*
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << t << std::endl;
  */

  const auto len = t.length();
  for (auto i = 0; i < len; i++)
  {
    switch (t[i])
    {
      case '1':
        std::cout << s1;
        break;
      case '2':
        std::cout << s2;
        break;
      case '3':
        std::cout << s3;
        break;
    }
  }
  std::cout << std::endl;
  return 0;
}
