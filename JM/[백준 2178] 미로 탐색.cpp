#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
char arr[101][101];
int ans[101][101];
int visited[101][101];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void searchRoute(int x, int y) {
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (arr[nextX][nextY] == '1' && visited[nextX][nextY] == 0) {
					ans[nextX][nextY] = ans[x][y] + 1;
					visited[nextX][nextY] = 1;
					q.push({ nextX, nextY });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string tmp; cin >> tmp;
		for (int j = 0; j < m; ++j) arr[i][j] = tmp[j];
	}

	ans[0][0] = 1;
	searchRoute(0, 0);
	cout << ans[n-1][m-1] << '\n';
}