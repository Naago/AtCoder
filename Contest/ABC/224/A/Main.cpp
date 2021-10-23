#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;

	const auto len = s.length();
	if (s[len - 1] == 'r')
	{
		std::cout << "er" << std::endl;
		return 0;
	}
	std::cout << "ist" << std::endl;
	return 0;
}
