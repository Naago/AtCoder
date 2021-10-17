#include <iostream>
#include <iomanip>

struct Pos
{
	Pos() : d(0.0), n(0) {}
	double d;
	int n;
};

struct Line
{
	Line() : Len(0), Sp(0), Total(0) {}
	int Len;
	int Sp;
	int Total;
};

Line sLine[100000];

bool Check(double &d, Pos &l, Pos &r)
{
	if (l.n == r.n)
	{
		Line &li = sLine[l.n];
		d = li.Total + l.d;
		d += (static_cast<double>(li.Len) - l.d - r.d) / 2;
		return false;
	}

	Line &ll = sLine[l.n];
	const auto tl = (static_cast<double>(ll.Len) - l.d) / ll.Sp;

	Line &lr = sLine[r.n];
	const auto tr = (static_cast<double>(lr.Len) - r.d) / lr.Sp;

	if (tl <= tr)
	{
		l.n++;
		l.d = 0.0;

		r.d += lr.Sp * tl;
		return true;
	}

	r.n--;
	r.d = 0.0;

	l.d += ll.Sp * tr;
	return true;
}

double F(int n, int t)
{
	Pos l, r;
	r.n = n - 1;

	double d;
	while (Check(d, l, r));
	return d;
}

int main()
{
	int n;
	std::cin >> n;

	int t = 0;
	for (auto i = 0; i < n; i++)
	{
		Line &l = sLine[i];
		std::cin >> l.Len;
		std::cin >> l.Sp;
		l.Total = t;
		t += l.Len;
	}

	const auto r = F(n, t);
	std::cout << r << std::endl;
	// std::cout << std::fixed << std::setprecision(10) << r << std::endl;
	return 0;
}
