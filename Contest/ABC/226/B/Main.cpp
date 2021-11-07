#include <iostream>
#include <vector>

bool F(const std::vector<std::vector<int> > &v0, const std::vector<std::vector<int> > &v1, const std::vector<int> &va, int l)
{
	if (v1[l - 1].empty())
	{
		return true;
	}

	auto vv1 = v1[l - 1];

	for (auto i = 0; i < l; i++)
	{
		auto iter = vv1.begin();
		while (iter != vv1.end())
		{
			if (va[i] != v0[*iter][i])
			{
				if (vv1.size() <= 1)
				{
					return true;	// 一致したものがない
				}

				iter = vv1.erase(iter);
				continue;
			}
			iter++;
		}
	}
	return false;	// 一致したものがあった
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::vector<int> > v0(n);
	std::vector<std::vector<int> > v1(200000);

	int r = 0;
	for (auto i = 0; i < n; i++)
	{
		int l;
		std::cin >> l;

		std::vector<int> &v = v0[r];
		v.reserve(l);
		v.resize(l);

		for (auto j = 0; j < l; j++)
		{
			std::cin >> v[j];
		}

		if (F(v0, v1, v, l))
		{
			v1[l - 1].push_back(r);
			++r;
		}
	}
	std::cout << r << std::endl;
	return 0;
}
