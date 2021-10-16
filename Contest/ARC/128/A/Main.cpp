#include <iostream>

struct Data
{
	Data() : rate(0), exchange(false) {}
	int rate;
	bool exchange;
};

Data sData[200000];

int main()
{
	int n;
	std::cin >> n;

	std::cin >> sData[0].rate;

	for (auto i = 1; i < n; i++)
	{
		std::cin >> sData[i].rate;

		if (sData[i - 1].rate > sData[i].rate)
		{
			sData[i - 1].exchange ^= true;
			sData[i].exchange ^= true;
		}
	}

	for (auto i = 0; i < n - 1; i++)
	{
		std::cout << (sData[i].exchange ? 1 : 0) << " ";
	}
	std::cout << (sData[n - 1].exchange ? 1 : 0) << std::endl;
	return 0;
}
