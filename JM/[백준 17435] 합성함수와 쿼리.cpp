#include <iostream>
#include <cmath>
using namespace std;

int arr[500001][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m; cin >> m;
	for (int i = 1; i <= m; ++i) cin >> arr[i][0];

	int len = 19;
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= m; ++j) {
			arr[j][i] = arr[arr[j][i - 1]][i - 1];
		}
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		for (int i = 18; i >= 0; --i) {
			if (a & (1 << i)) b = arr[b][i];
		}
		cout << b << '\n';
	}
}