#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node 
{
	int num;
	vector<int> link;
	int isVisited_forDFS = 0;
	int isVisited_forBFS = 0;
};

node vertexes[1001];

void DFS(int a)
{
	if (vertexes[a].isVisited_forDFS != 0) return;
	cout << vertexes[a].num << ' ';
	vertexes[a].isVisited_forDFS = 1;
	for (int i = 0; i < vertexes[a].link.size(); ++i) {
		int next = vertexes[a].link[i];
		DFS(next);
	}
}

queue<int> bfs_Q;
void BFS(int a) 
{
	if (vertexes[a].isVisited_forBFS == 0)
	{
		cout << vertexes[a].num << ' ';
		vertexes[a].isVisited_forBFS = 1;
		for (int i = 0; i < vertexes[a].link.size(); ++i) bfs_Q.push(vertexes[a].link[i]);
	}

	if (!bfs_Q.empty()) 
	{
		int next = bfs_Q.front();
		bfs_Q.pop();
		BFS(next);
	}
}

int main()
{
	int n, m, v; cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) 
	{
		int a, b; cin >> a >> b;
		vertexes[a].link.push_back(b);
		vertexes[b].link.push_back(a);
	}

	for (int i = 1; i <= n; ++i)
	{
		vertexes[i].num = i;
		sort(vertexes[i].link.begin(), vertexes[i].link.end());
	}

	DFS(v);
	cout << '\n';
	BFS(v);
}