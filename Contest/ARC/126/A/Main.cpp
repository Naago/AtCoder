#include <iostream>

int64_t F442(int64_t &n2, int64_t &n3, int64_t &n4)
{
  auto m = n4 / 2;
  if (m <= n2)
  {
    n4 -= m * 2;
    n2 -= m;
    return m;
  }

  m = n2;
  n2 = 0;
  n4 -= m * 2;
  return m;
}

int64_t F433(int64_t &n2, int64_t &n3, int64_t &n4)
{
  auto m = n4;
  if (m * 2 <= n3)
  {
    n4 = 0;
    n3 -= m * 2;
    return m;
  }
  m = n3 / 2;
  n4 -= m;
  n3 -= m * 2;
  return m;
}

int64_t F4222(int64_t &n2, int64_t &n3, int64_t &n4)
{
  auto m = n4;
  if (m * 3 <= n2)
  {
    n4 = 0;
    n2 -= m * 3;
    return m;
  }
  
  m = n2 / 3;
  n4 -= m;
  n2 -= m * 3;
  return m;
}

int64_t F3322(int64_t &n2, int64_t &n3, int64_t &n4)
{
  auto m = n3 / 2;
  if (m * 2 <= n2)
  {
    n3 -= m * 2;
    n2 -= m * 2;
    return m;
  }
  
  m = n2 / 2;
  n3 -= m * 2;
  n2 -= m * 2;
  return m;
}

int64_t F22222(int64_t &n2, int64_t &n3, int64_t &n4)
{
  auto m = n2 / 5;
  n2 -= m * 5;
  return m;
}

int64_t F0(int64_t n2, int64_t n3, int64_t n4)
{
  int64_t sum = 0;
  sum += F442(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F433(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F4222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F3322(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F22222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  return sum;
}

int64_t F1(int64_t n2, int64_t n3, int64_t n4)
{
  int64_t sum = 0;
  sum += F433(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F442(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F4222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F3322(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F22222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  return sum;
}

int64_t F2(int64_t n2, int64_t n3, int64_t n4)
{
  int64_t sum = 0;
  sum += F442(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F433(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F3322(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F4222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F22222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  return sum;
}

int64_t F3(int64_t n2, int64_t n3, int64_t n4)
{
  int64_t sum = 0;
  sum += F433(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F442(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F3322(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F4222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  sum += F22222(n2, n3, n4);
  //std::cout << sum << "," << n2 << "," << n3 << "," << n4 << std::endl;
  return sum;
}
int main()
{
  int t;
  std::cin >> t;
  //std::cout << t << std::endl;

  for (auto i = 0; i < t; i++)
  {
    int64_t n2, n3, n4;
    std::cin >> n2 >> n3 >> n4;
    //std::cout << n2 << "," << n3 << "," << n4 << std::endl;

    int64_t sum = 0;
    sum = F0(n2, n3, n4);
    {
      auto tmp = F1(n2, n3, n4);
      if (tmp > sum){ sum = tmp; }
    }
    {
      auto tmp = F2(n2, n3, n4);
      if (tmp > sum){ sum = tmp; }
    }
    {
      auto tmp = F3(n2, n3, n4);
      if (tmp > sum){ sum = tmp; }
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
