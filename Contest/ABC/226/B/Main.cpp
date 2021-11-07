#include <iostream>
#include <vector>
#include <set>

int main()
{
	int n;
	std::cin >> n;

	std::set<std::vector<int> > s;

	for (auto i = 0; i < n; i++)
	{
		int l;
		std::cin >> l;

		std::vector<int> v(l);

		for (auto j = 0; j < l; j++)
		{
			std::cin >> v[j];
		}

		s.insert(v);
	}
	std::cout << s.size() << std::endl;
	return 0;
}
