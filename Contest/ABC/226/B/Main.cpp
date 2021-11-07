#include <iostream>
#include <vector>

bool F0(const std::vector<int> &a, const std::vector<int> &b, int l)
{
	for (auto i = 0; i < l; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

bool F(int i, const std::vector<std::vector<int> > &v0, const std::vector<std::vector<int> > &v1, const std::vector<int> &va, int l)
{
	const auto &vv1 = v1[l - 1];

	for (auto j = 0; j < vv1.size(); j++)
	{
		const auto &vb = v0[vv1[j]];
		if (F0(vb, va, l))
		{
			return false;
		}
	}
	return true;
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

		if (F(r, v0, v1, v, l))
		{
			v1[l - 1].push_back(r);
			++r;
		}
	}
	std::cout << r << std::endl;
	return 0;
}
