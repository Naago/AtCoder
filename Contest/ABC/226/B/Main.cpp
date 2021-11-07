#include <iostream>
#include <vector>

bool F(const std::vector<std::vector<int> > &v0, const std::vector<std::vector<int> > &v1, const std::vector<int> &va, int l)
{
	const auto &vv1 = v1[l - 1];
	if (vv1.empty())
	{
		return true;
	}

	std::vector<bool> a(vv1.size(), true);

	int cnt = 0;
	for (auto i = 0; i < l; i++)
	{
		for (auto j = 0; j < vv1.size(); j++)
		{
			if (va[i] != v0[vv1[j]][i])
			{
				if (a[j])
				{
					a[j] = false;
					if (++cnt >= vv1.size())
					{
						return true;	// 一致したものがない
					}
				}
			}
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
