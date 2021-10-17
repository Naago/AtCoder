#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;

	auto s0 = s;
	auto s1 = s;

	const auto len = s.length();
	for (auto i = 1; i < len; i++)
	{
		s += s[0];
		s.erase(0, 1);

		// std::cout << s << std::endl;

		if (s0 > s)
		{
			s0 = s;
		}
		if (s1 < s)
		{
			s1 = s;
		}
	}

	std::cout << s0 << std::endl;
	std::cout << s1 << std::endl;
	return 0;
}
