#include <iostream>

int main()
{
	int x;
	std::cin >> x;

	if (x < 100)
	{
		std::cout << "No" << std::endl;
		return 0;
	}

	std::cout << (((x % 100) == 0) ? "Yes" : "No") << std::endl;
	return 0;
}
