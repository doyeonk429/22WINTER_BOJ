#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

void postorder(int left, int right) {
	if (left == right) {
		cout << v[left] << ' '; 
		return;
	}
	int mid = (left + right) / 2;
	postorder(left, mid - 1);
	postorder(mid + 1, right);
	cout << v[mid] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	
	int t = 0;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
		if (tmp == -1) t = i;
	}
	cin >> v[t];
	stable_sort(v.begin(), v.end());

	postorder(0, n-1);
}