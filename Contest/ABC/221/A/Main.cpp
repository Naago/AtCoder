#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	// std::cout << a << ", " << b << std::endl;

	auto n = 1;
	for (auto i = 0; i < (a - b); i++)
	{
		n *= 32;
	}

	std::cout << n << std::endl;
	return 0;
}
