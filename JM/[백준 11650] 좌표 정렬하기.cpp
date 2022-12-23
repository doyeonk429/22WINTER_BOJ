#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};

bool compare(point a, point b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main() {
	int n; cin >> n;
	vector <point> v;

	for (int i = 0; i < n;++i) {
		point tmp;
		cin >> tmp.x >> tmp.y;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; ++i) cout << v[i].x << ' ' << v[i].y << '\n';
}
