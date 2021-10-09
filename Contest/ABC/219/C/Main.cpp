#include <iostream>
#include <string>
#include <vector>
#include <map>

void Sort(const std::vector<std::string> &v, std::vector<int> &idx,
          const std::map<int, int> &m, int i, int j)
{
//   const auto &si = v[idx[i]];
//   const auto &sj = v[idx[j]];
  
//   const auto len = si.length();
//   for (auto p = 0; p < len; p++)
//   {
//     const auto vi = m[si[p]];
//     if (m[(char)si[p]] > m[(char)sj[p]])
//     {
//       const auto tmp = idx[i];
//       idx[i] = idx[j];
//       idx[j] = tmp;
//       return;
//     }
//   }
}

int main()
{
  std::string x;
  int n;
  std::cin >> x >> n;
  
  std::map<int, int> m;
  const auto xlen = x.length();
  for (auto i = 0; i < xlen; i++)
  {
    m[x[i]] = (int)i;
  }

  std::vector<std::string> v;
  v.reserve(n);
  for (auto i = 0; i < n; i++)
  {
    std::cin >> v[i];
    //std::cout << v[i] << std::endl;
  }
  
  std::vector<int> idx;
  idx.reserve(n);
  for (auto i = 0; i < n; i++)
  {
    idx[i] = i;
  }
  
  for (auto i = 0; i < n - 1; i++)
  {
    for (auto j = i + 1; j < n; j++)
    {
      Sort(v, idx, m, i, j);
    }
  }
  
  for (auto i = 0; i < n; i++)
  {
    std::cout << v[idx[i]] << std::endl;
  }
  return 0;
}
