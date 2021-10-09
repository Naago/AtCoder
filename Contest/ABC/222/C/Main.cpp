#include <iostream>

struct Player
{
	Player() : no(0), win(0){}

	std::string te;
	int no;
	int win;
};

Player sPlayer[100];

void Battle(int m, Player &p0, Player &p1)
{
	const auto &te0 = p0.te[m];
	const auto &te1 = p1.te[m];

	if (((te0 == 'G') && (te1 == 'C'))
		|| ((te0 == 'C') && (te1 == 'P'))
		|| ((te0 == 'P') && (te1 == 'G')))
	{
		++p0.win;
	}
	else if (te0 != te1)
	{
		++p1.win;
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	Player *p[100] = {0};
	for (auto i = 0; i < (n * 2); i++)
	{
		auto &pl = sPlayer[i];
		std::cin >> pl.te;
		pl.no = i + 1;
		pl.win = 0;
		p[i] = &pl;
	}

	for (auto mm = 0; mm < m; mm++)
	{
		for (auto k = 0; k < n; k++)
		{
			Battle(mm, *p[k * 2], *p[(k * 2) + 1]);
		}

		for (auto i = 0; i < (n * 2) - 1; i++)
		{
			for (auto j = i + 1; j < (n * 2); j++)
			{
				if ((p[i]->win < p[j]->win)
					|| ((p[i]->win == p[j]->win) && (p[i]->no > p[j]->no)))
				{
					Player *tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}
	}

	for (auto i = 0; i < (n * 2); i++)
	{
		std::cout << p[i]->no << std::endl;
	}
	return 0;
}
