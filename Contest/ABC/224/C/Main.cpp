#include <iostream>

struct Pos
{
	Pos() : x(0), y(0) {}
	int x, y;
};

Pos P[300];

double F0(int i0, int i1)
{
	const double d = static_cast<double>(P[i1].y - P[i0].y) / (P[i1].x - P[i0].x);
	return d;
}

bool F(int i0, int i1, int i2)
{
	// 傾きが無限大？
	if (P[i0].x == P[i1].x)
	{
		if (P[i0].x != P[i2].x)
		{
			return true;
		}
		return false;
	}
	if (P[i0].x == P[i2].x)
	{
		if (P[i0].x != P[i1].x)
		{
			return true;
		}
		return false;
	}

	const auto d0 = F0(i0, i1);
	const auto d1 = F0(i0, i2);
	// const auto GOSA = 0.000000000001;
	// return ((d0 < (d1 - GOSA)) || (d0 > (d1 + GOSA)));
	return (d0 != d1);
}

int main()
{
	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::cin >> P[i].x >> P[i].y;
	}

	int sum = 0;
	for (auto i0 = 0; i0 < n - 2; i0++)
	{
		for (auto i1 = i0 + 1; i1 < n - 1; i1++)
		{
			for (auto i2 = i1 + 1; i2 < n; i2++)
			{
				if (F(i0, i1, i2))
				{
					++sum;
				}
			}
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
