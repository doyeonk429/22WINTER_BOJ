#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];

int main() {
	int n; cin >> n;
	int cost[3];

	for (int i = 1; i <= n; ++i) {
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[2];
	}
	
	int ans = min({ arr[n][0], arr[n][1], arr[n][2] });
	cout << ans << '\n';
}