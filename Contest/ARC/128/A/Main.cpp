#include <iostream>

struct Data
{
	Data() : gold(0.0), silver(0.0), exchange(false) {}
	double gold;
	double silver;
	bool exchange;
};

Data sData[200001];

int main()
{
	int n;
	std::cin >> n;

	sData[0].gold = 1.0;
	for (auto i = 0; i < n; i++)
	{
		int rate;
		std::cin >> rate;
		sData[i + 1].gold = std::max<double>(sData[i].gold, sData[i].silver / rate);
		sData[i + 1].silver = std::max<double>(sData[i].silver, sData[i].gold * rate);
	}

	bool is_gold = true;
	for (auto i = n; i >= 0; i--)
	{
		if (is_gold)
		{
			if (sData[i].gold != sData[i - 1].gold)
			{
				sData[i].exchange = true;
				is_gold = false;
			}
		}
		else
		{
			if (sData[i].silver != sData[i - 1].silver)
			{
				sData[i].exchange = true;
				is_gold = true;
			}
		}
	}

	for (auto i = 1; i < n + 1; i++)
	{
		std::cout << (sData[i].exchange ? 1 : 0);
		if (i < n)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
