#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	// std::cout << a << ", " << b << ", " << c << std::endl;

	int d = c;

	while (d <= 1000)
	{
		if ((d >= a) && (d <= b))
		{
			break;
		}
		d += c;
	}

	if (d > 1000)
	{
		d = -1;
	}

	std::cout << d << std::endl;
	return 0;
}
