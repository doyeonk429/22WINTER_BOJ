#include <iostream>
#include <cmath>
using namespace std;

int arr[21][21];
bool visited[22];
int n;
int ans = 1234567890;

void dfs(int cnt, int pos) {
	if (cnt == n / 2) {
		int s = 0;
		int l = 0;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (visited[i] == true && visited[j] == true) s += arr[i][j];
				if (visited[i] == false && visited[j] == false) l += arr[i][j];
			}
		}

		int tmp = abs(s - l);
		ans = min(tmp, ans);
		return;
	}

	for (int i = pos; i < n; ++i) {
		visited[i] = true;
		dfs(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1);
	cout << ans;
}