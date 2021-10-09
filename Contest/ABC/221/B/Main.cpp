#include <iostream>
#include <string>

int main()
{
	std::string s, t;
	std::cin >> s >> t;
	// std::cout << s << ", " << t << std::endl;

	const auto len = s.length();
	auto flag = false;

	for (auto i = 0; i < len; i++)
	{
		if (s[i] == t[i])
		{
			continue;
		}

		if (flag	// 2箇所目以降の相違点
			|| (i + 1 >= len))	// 最後の1文字？
		{
			std::cout << "No" << std::endl;
			return 0;
		}

		// 入れ替えで一致する？
		if ((s[i + 1] == t[i]) && (s[i] == t[i + 1]))
		{
			flag = true;
			i++;
			continue;
		}

		std::cout << "No" << std::endl;
		return 0;
	}
	std::cout << "Yes" << std::endl;
	return 0;
}
