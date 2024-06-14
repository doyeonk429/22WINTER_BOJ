#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

int main()
{
	TIMME;

	int n;
	string exp;
	cin >> n >> exp;

	vector<int> v(n);
	stack<double> S;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= 'A' && exp[i] <= 'Z')  S.push(v[exp[i] - 'A']);
		else
		{
			if (!S.empty())
			{
				double tmp = S.top(); S.pop();
				if (exp[i] == '+')	tmp = S.top() + tmp;
				else if (exp[i] == '-')	tmp = S.top() - tmp;
				else if (exp[i] == '*')	tmp = S.top() * tmp;
				else if (exp[i] == '/')	tmp = S.top() / tmp;
				S.pop();
				S.push(tmp);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << S.top() << '\n';

	return 0;
}