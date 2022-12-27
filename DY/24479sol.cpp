#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, r;
vector<int> arr[100001];
bool visited[100001];
int orderCount[100001];
int orderNum = 0;

void DFS(int r)
{
	if (visited[r])
	{
		return;
	}
	else
	{
		visited[r] = true;
		orderNum++;
		orderCount[r] = orderNum;

		for (int i = 0; i < arr[r].size(); i++)
		{
			DFS(arr[r][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int v, u; cin >> v >> u;
		arr[v].push_back(u);
		arr[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}
	DFS(r);
	for (int i = 1; i <= n; i++)
	{
		cout << orderCount[i] << "\n";
	}
	return 0;
}
