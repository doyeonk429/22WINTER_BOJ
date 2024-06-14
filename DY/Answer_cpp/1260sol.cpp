#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int arr[1001][1001];
bool visited[1001];
queue<int> q;

void DFS(int vertex)
{
	visited[vertex] = true;
	cout << vertex << " ";

	for (int i = 1; i <= n; i++)
	{
		if (arr[vertex][i] == true && !visited[i])
		{
			DFS(i);
		}
	}
}
void BFS(int vertex)
{
	q.push(vertex);
	visited[vertex] = true;
	cout << vertex << " ";

	while (!q.empty())
	{
		vertex = q.front();	q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (arr[vertex][i] == true && !visited[i])
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	DFS(v);
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	BFS(v);
	cout << endl;

	return 0;
}