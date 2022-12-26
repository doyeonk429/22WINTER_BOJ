#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int> > pq;
	int n;
	cin >> n;
	int a;
	for (int j = 0; j < n*n; j++)
	{
		cin >> a;
		pq.push(a);
		if (pq.size() > n)
		{
			pq.pop();
		}
	}
	cout << pq.top();
	return 0;
}