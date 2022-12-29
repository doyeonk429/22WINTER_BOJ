#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	map<string, int> a;

	for (int i = 0; i < n; ++i) {
		string tmp; cin >> tmp;
		int len = tmp.length();

		if (len < m) continue;
		else {
			if (a.find(tmp) != a.end()) a[tmp]++;
			else a.insert({ tmp, 1 });
		}
	}

	vector<pair<string, int>> v(a.begin(), a.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); ++i) cout << v[i].first << '\n';
}