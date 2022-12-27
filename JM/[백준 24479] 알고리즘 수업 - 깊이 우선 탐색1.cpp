#include <iostream>
#include <queue>
using namespace std;

struct node {
	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> link;
};

node nodes[100001];

void dfs(int cur, int& cnt) {
	if (nodes[cur].cnt != 0) return;
	nodes[cur].cnt = cnt;
	cnt++;
	while (!nodes[cur].link.empty()) {
		int next = nodes[cur].link.top();
		nodes[cur].link.pop();
		dfs(next, cnt);
	}
}

int main() {
	int n, m, r; cin >> n >> m >> r;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		nodes[a].link.push(b);
		nodes[b].link.push(a);
	}

	int cnt = 1;
	dfs(r, cnt);
	for (int i = 1; i <= n; ++i) cout << nodes[i].cnt << '\n';
}