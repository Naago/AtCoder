#include <iostream>

int64_t F(int64_t a, int k)
{
	int64_t s = 0;
	int n = 1;

	do
	{
		s += (a % 10) * n;
		a /= 10;
		n *= k;
	}
	while (a);
	return s;
}

int main()
{
	int k;
	int64_t a, b;
	std::cin >> k >> a >> b;
	// std::cout << k << ", " << a << ", " << b << std::endl;

	const auto a0 = F(a, k);
	const auto b0 = F(b, k);
	std::cout << (a0 * b0) << std::endl;
	return 0;
}
