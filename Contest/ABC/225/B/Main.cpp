#include <iostream>

struct AB
{
	AB() : a(0), b(0){}
	int a, b;
};

AB sLine[99999];
bool sLive[100000];

void Output(bool flag)
{
	std::cout << (flag ? "Yes" : "No") << std::endl;
}

int main()
{
	int n;
	std::cin >> n;

	int a0, b0;
	std::cin >> a0 >> b0;

	if (a0 == b0)
	{
		Output(false);
		return 0;
	}

	sLine[0].a = a0;
	sLine[0].b = b0;

	for (auto i = 1; i < n - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;

		if (a == b)
		{
			Output(false);
			return 0;
		}
		if ((a != a0) && (a != b0) && (b != a0) && (b != b0))
		{
			Output(false);
			return 0;
		}

		if ((a0 != a) && (a0 != b)) { a0 = 0; }
		if ((b0 != a) && (b0 != b)) { b0 = 0; }

		if (!a0 && !b0)
		{
			Output(false);
			return 0;
		}

		sLine[i].a = a;
		sLine[i].b = b;
	}

	if (a0 && b0)
	{
		Output(false);
		return 0;
	}

	int r = 0;
	if (!a0) { r = b0; }
	else { r = a0; }

	sLive[r - 1] = true;

	for (auto i = 0; i < n - 1; i++)
	{
		const auto t = (sLine[i].a == r) ? sLine[i].b : sLine[i].a;
		if (sLive[t - 1])
		{
			Output(false);
			return 0;
		}
		sLive[t - 1] = true;
	}

	Output(true);
	return 0;
}
