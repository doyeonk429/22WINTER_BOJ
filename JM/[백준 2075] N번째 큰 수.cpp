#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	int cnt = n * n;
	for (int i = 0; i < cnt; ++i) {
		int tmp; cin >> tmp;
		pq.push(tmp);
		if (pq.size() > n) pq.pop();
	}

	cout << pq.top() << '\n';
}
