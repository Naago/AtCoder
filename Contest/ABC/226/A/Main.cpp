#include <iostream>

int main()
{
	float f;
	std::cin >> f;

	int n = static_cast<int>(f);

	const int n10 = static_cast<int>(f * 10);
	if (n10 % 10 >= 5)
	{
		n += 1;
	}

	std::cout << n << std::endl;
	return 0;
}
