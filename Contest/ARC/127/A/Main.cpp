#include <iostream>

int Next(int64_t n, int keta)
{
	auto ret = 0;
	for (auto i = 0; i < keta; i++)
	{
		ret = n % 10;
		n /= 10;
	}
	return ret;
}

int Keta(int64_t n)
{
	auto ret = 0;
	while(n >= 10)
	{
		n /= 10;
		++ret;
	}
	return ret;
}

int64_t Pow(int keta)
{
	int64_t ret = 1;
	for (auto i = 0; i < keta; i++)
	{
		ret *= 10;
	}
	return ret;
}

// 0 -> 1
// 1 -> 11 + 1
// 2 -> 111 + 11 + 1
int64_t Full(int keta)
{
	auto tmp = Pow(keta);
	int64_t ret = 0;
	for (auto i = 0; i < keta + 1; i++)
	{
		ret += tmp * (i + 1);
		tmp /= 10;
	}
	return ret;
}

// 0 -> 1
// 1 -> 11
// 2 -> 111
int64_t Full2(int keta)
{
	auto tmp = Pow(keta);
	auto ret = 0;

	while (tmp > 0)
	{
		ret += tmp;
		tmp /= 10;
	}
	return ret;
}

int64_t F(int64_t n, int keta, bool is_plus)
{
	const auto base = Pow(keta);
	if (n >= base * 2)
	{
		return Full(keta);
	}

	// 先頭が1の場合の対応
	if (keta == 0)
	{
		return 1;
	}

	auto num = n - base + 1;
	const auto next = Next(n, keta);

	if (next >= 2)
	{
		num += Full2(keta - 1);
	}
	else if(next == 1)
	{
		num += F(n - base, keta - 1, false);
	}

	// 下位の分を足す
	if (is_plus)
	{
		num += Full(keta - 1);
	}
	return num;
}

int main()
{
	int64_t n;
	std::cin >> n;
	// std::cout << n << std::endl;

	const auto keta = Keta(n);
	// std::cout << keta << std::endl;

	std::cout << F(n, keta, true) << std::endl;
	return 0;
}
