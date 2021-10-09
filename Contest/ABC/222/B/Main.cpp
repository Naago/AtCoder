#include <iostream>

int main()
{
	int n, p;
	std::cin >> n >> p;

	int t;
	int c = 0;
	for (auto i = 0; i < n; i++)
	{
		std::cin >> t;
		if (t < p)
		{
			++c;
		}
	}
	std::cout << c << std::endl;
	return 0;
}
