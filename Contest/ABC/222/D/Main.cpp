#include <iostream>
#include <vector>

int sVal[2][3001];

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> v0(n);
	std::vector<int> v1(n);

	for (auto i = 0; i < n; i++)
	{
		std::cin >> v0[i];
	}
	for (auto i = 0; i < n; i++)
	{
		std::cin >> v1[i];
	}

	int t = 0;
	for (auto i = v0[0]; i <= v1[0]; i++)
	{
		sVal[t][i] = 1;
	}

	// if (n >= 2)
	// {
	// 	t = ~t;
	// }

	int64_t r = 0;
	for (auto i = v0[0]; i < v1[0]; i++)
	{
		r += sVal[t][i];
	}
	std::cout << r % 998244353 << std::endl;
	return 0;
}
