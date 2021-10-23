#include <iostream>

struct Pos
{
	Pos() : x(0), y(0) {}
	int x, y;
};

Pos P[300];

bool F(int i0, int i1, int i2)
{
	const auto &p0 = P[i0];
	const auto &p1 = P[i1];
	const auto &p2 = P[i2];

	const auto y1 = p1.y - p0.y;
	const auto x1 = p1.x - p0.x;

	const auto y2 = p2.y - p0.y;
	const auto x2 = p2.x - p0.x;

	const int64_t d0 = y1 * x2;
	const int64_t d1 = y2 * x1;

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
