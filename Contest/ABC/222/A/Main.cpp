#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	if (n >= 1000)
	{
		std::cout << n << std::endl;
		return 0;
	}
	if (n >= 100)
	{
		std::cout << "0" << n << std::endl;
		return 0;
	}
	if (n >= 10)
	{
		std::cout << "00" << n << std::endl;
		return 0;
	}

	std::cout << "000" << n << std::endl;
	return 0;
}
