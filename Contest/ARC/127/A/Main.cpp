#include <iostream>

int64_t F(int64_t n, int64_t d, int64_t d0)
{
	int64_t sum = 0;
	if (n >= d)
	{
		const int64_t m = std::min<int64_t>(n, d + d0 - 1);
		// std::cout << "n: " << n << ", d: " << d << ", d0: " << d0 << ", m: " << m << std::endl; 
		sum += m - d + 1;
	}

	if ((d % 10) == 0)
	{
		sum += F(n, d / 10, d0 / 10);
	}
	return sum;
}

int main()
{
	int64_t n;
	std::cin >> n;
	// std::cout << n << std::endl;

	int64_t sum = 0;
	int64_t d = 0, d0 = 1000000000000000;

	while (d0 > 0)
	{
		d += d0;
		sum += F(n, d, d0);
		d0 /= 10;
	}
	std::cout << sum << std::endl;
	return 0;
}
