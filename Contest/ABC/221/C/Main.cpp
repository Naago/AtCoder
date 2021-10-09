#include <iostream>
#include <vector>

int Keta(int64_t n)
{
	int keta = 1;
	while (true)
	{
		if (n < 10)
		{
			break;
		}

		n /= 10;
		++keta;
	}
	return keta;
}

int64_t Pow(int n)
{
	int64_t result = 1;
	for (auto i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int64_t Num(int a[10], int n)
{
	int64_t result = 0;
	for (auto i = 0; i < n; i++)
	{
		result += a[i] * Pow(n - i - 1);
	}
	return result;
}

void Insert(int (*a)[10], int &n, int value)
{
	for (auto i = n; i > 0; i--)
	{
		if (value < (*a)[i - 1])
		{
			(*a)[i] = value;
			++n;
			return;
		}

		(*a)[i] = (*a)[i - 1];
	}

	(*a)[0] = value;
	++n;
}

int64_t F(int d, const std::vector<int> &v)
{
	int a0[10] = {}; auto n0 = 0;
	int a1[10] = {}; auto n1 = 0;

	for (auto i = 0; i < v.size(); i++)
	{
		if (d & (1 << i))
		{
			Insert(&a0, n0, v[i]);
		}
		else
		{
			Insert(&a1, n1, v[i]);
		}
	}
	return Num(a0, n0) * Num(a1, n1);
}

int64_t F1(const std::vector<int> &v)
{
	int64_t result = 0;
	for (auto i = 0; i < v.size(); i++)
	{
		const auto d = 1 << i;
		const int64_t tmp = F(d, v);
		if (tmp > result) { result = tmp; }
	}
	return result;
}

int64_t F2(const std::vector<int> &v)
{
	int64_t result = 0;
	for (auto i = 0; i < v.size() - 1; i++)
	{
		auto d = 1 << i;
		for (auto j = i + 1; j < v.size(); j++)
		{
			d += 1 << j;
			const int64_t tmp = F(d, v);
			if (tmp > result) { result = tmp; }
		}
	}
	return result;
}

int64_t F3(const std::vector<int> &v)
{
	int64_t result = 0;
	for (auto i = 0; i < v.size() - 2; i++)
	{
		auto d = 1 << i;
		for (auto j = i + 1; j < v.size() - 1; j++)
		{
			d += 1 << j;
			for (auto k = j + 1; k < v.size(); k++)
			{
				d += 1 << k;
				const int64_t tmp = F(d, v);
				if (tmp > result) { result = tmp; }
			}
		}
	}
	return result;
}

int64_t F4(const std::vector<int> &v)
{
	int64_t result = 0;
	for (auto i = 0; i < v.size() - 3; i++)
	{
		auto d = 1 << i;
		for (auto j = i + 1; j < v.size() - 2; j++)
		{
			d += 1 << j;
			for (auto k = j + 1; k < v.size() - 1; k++)
			{
				d += 1 << k;
				for (auto m = k + 1; m < v.size(); m++)
				{
					d += 1 << m;
					const int64_t tmp = F(d, v);
					if (tmp > result) { result = tmp; }
				}
			}
		}
	}
	return result;
}

int main()
{
	int64_t n;
	std::cin >> n;
	// std::cout << n << std::endl;

	const auto keta = Keta(n);
	std::vector<int> v(keta);
	for (auto i = 0; i < keta; i++)
	{
		v[i] = n % 10;
		n /= 10;
	}

	int64_t result = 0;
	for (auto i = 0; i < keta / 2; i++)
	{
		int64_t tmp = 0;
		switch (i)
		{
		case 0:
			tmp = F1(v);
			break;
		case 1:
			tmp = F2(v);
			break;
		case 2:
			tmp = F3(v);
			break;
		case 3:
			tmp = F4(v);
			break;
		}

		if (tmp > result)
		{
			result = tmp;
		}
	}

	std::cout << result << std::endl;
	return 0;
}
