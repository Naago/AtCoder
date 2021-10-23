#include <iostream>

int sTbl[50][50];

bool Check(int i1, int i2, int j1, int j2)
{
	if (sTbl[i1][j1] + sTbl[i2][j2] <= sTbl[i2][j1] + sTbl[i1][j2])
	{
		// std::cout << "(" << i1 << ", " << i2 << ", " << j1 << ", " << j2 << ") => true" << std::endl;
		return true;
	}
	// std::cout << "(" << i1 << ", " << i2 << ", " << j1 << ", " << j2 << ") => false" << std::endl;
	return false;
}

bool F1(int h, int w, int i1, int i2)
{
	for (auto j1 = 0; j1 < w - 1; j1++)
	{
		for (auto j2 = j1 + 1; j2 < w; j2++)
		{
			if (!Check(i1, i2, j1, j2))
			{
				return false;
			}
		}
	}
	return true;
}

bool F0(int h, int w)
{
	for (auto i1 = 0; i1 < h - 1; i1++)
	{
		for (auto i2 = i1 + 1; i2 < h; i2++)
		{
			if (!F1(h, w, i1, i2))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int h, w;
	std::cin >> h >> w;

	for (auto hi = 0; hi < h; hi++)
	{
		for (auto wj = 0; wj < w; wj++)
		{
			std::cin >> sTbl[hi][wj];
		}
	}

	const bool result = F0(h, w);
	std::cout << (result ? "Yes" : "No") << std::endl;
	return 0;
}
