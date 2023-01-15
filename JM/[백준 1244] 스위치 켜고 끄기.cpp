#include <iostream>
#include <queue>
using namespace std;

int arr[101];

void changeStatement(int i) {
	if (arr[i] == 0) arr[i] = 1;
	else arr[i] = 0;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	int k; cin >> k;
	queue<int> q;
	for (int i = 0; i < k; ++i) {
		int a, b; cin >> a >> b;
		if (a == 1) { // 남학생
			for (int j = b; j <= n; j += b) changeStatement(j);
		}
		else { // 여학생
			for (int j = 1; j <= n; ++j) {
				if ((b - j <= 0) || (b + j > n)) break;
				if (arr[b - j] != arr[b + j]) break;
				q.push(j);
			}

			changeStatement(b);
			while (!q.empty()) {
				changeStatement(b - q.front());
				changeStatement(b + q.front());
				q.pop();
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << arr[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
}