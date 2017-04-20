//Johnny Tran
//Test the swap function template
#include<iostream>
#include"SwapTemplate.h"
#include<string>

using namespace std;

void main()
{
	int a = 1, b = 2;
	double c = .1, d = .2;
	char e = 'a', f = 'b';
	string g = "yes", h = "no";

	swap(a, b);
	swap(c, d);
	swap(e, f);
	swap(g, h);

	cout << a << ", " << b << endl;
	cout << c << ", " << d << endl;
	cout << e << ", " << f << endl;
	cout << g << ", " << h << endl;

	system("pause");
}