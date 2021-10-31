#include <iostream>

int main()
{
	std::string s[6];
	std::cin >> s[0];

	s[1] += s[0][0];
	s[1] += s[0][2];
	s[1] += s[0][1];

	s[2] += s[0][1];
	s[2] += s[0][0];
	s[2] += s[0][2];

	s[3] += s[0][1];
	s[3] += s[0][2];
	s[3] += s[0][0];

	s[4] += s[0][2];
	s[4] += s[0][0];
	s[4] += s[0][1];

	s[5] += s[0][2];
	s[5] += s[0][1];
	s[5] += s[0][0];

	int cnt = 0;
	std::string *sp[6] = {0};

	for (auto i = 0; i < 6; i++)
	{
		bool ok = true;

		for (auto j = 0; j < cnt; j++)
		{
			if (s[i] == *sp[j])
			{
				ok = false;
				break;
			}
		}

		if (!ok)
		{
			continue;
		}

		sp[cnt++] = &s[i];
	}

	std::cout << cnt << std::endl;
	return 0;
}
