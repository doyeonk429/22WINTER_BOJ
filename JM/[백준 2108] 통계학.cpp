/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt[8001]; // -4000~4000
double sum;

int main() {
	int n; cin >> n;

	vector <int> v;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		sum += tmp;
		v.push_back(tmp);
		cnt[tmp+4000]++;
	}
	sort(v.begin(), v.end());

	// »ê¼úÆò±Õ
	int avg = round(sum / n);
	if (avg == -0) cout << 0 << '\n';
	else cout << avg << '\n';

	// Áß¾Ó°ª
	int middle = round(n / 2);
	cout << v[middle] << '\n';

	// ÃÖºó°ª
	vector <int> k;
	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[v[i]+4000] > num) {
			k.clear();
			k.push_back(v[i]);
			num = cnt[v[i]+4000];
		}
		else if (cnt[v[i]+4000] == num) {
			k.push_back(v[i]);
		}
	}
	sort(k.begin(), k.end());
	k.erase(unique(k.begin(), k.end()), k.end());

	if (k.size() >= 2) cout << k[1] << '\n';
	else cout << k[0] << '\n';

	// ¹üÀ§
	cout << v[n - 1] - v[0] << '\n';
}*/