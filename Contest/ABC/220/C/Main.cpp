#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int64_t> v(n);
	int64_t s = 0;

	for (auto i = 0; i < n; i++)
	{
		int64_t t;
		std::cin >> t;
		v[i] = t;
		s += t;
	}

	int64_t x;
	std::cin >> x;

	const auto a = x / s; // 数列Aの繰り返し回数
	auto r = x - (a * s);	// 余り

	int64_t i = 0;
	for (; i < n; i++)
	{
		if (r < v[i])
		{
			break;
		}
		r -= v[i];
	}

	std::cout << ((a * n) + i + 1) << std::endl;
	return 0;
}
