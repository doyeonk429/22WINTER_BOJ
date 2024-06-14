#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

int main()
{
	TIMME;
	stack<char> s;
	string a;
	int ans = 0;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '(')	s.push(a[i]);
		else
		{
			if (a[i - 1] == '(') { s.pop(); ans += s.size(); }
			else { s.pop(); ans++; }	
		}
	}
	cout << ans;
}