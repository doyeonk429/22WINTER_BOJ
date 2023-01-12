#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Count;
vector<int> A(131072);
vector<int> v;
int idx = 0;

void First(int x) {
	if (x <= Count)
	{
		First(x * 2);
		A[x] = v[idx++];
		First(x * 2 + 1);
	}
	else
		return;
}

void Second(int x) {
	if (x <= Count)
	{
		Second(x * 2);
		Second(x * 2 + 1);
		cout << A[x] << " ";
	}
	else
		return;
	
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int x;
	cin >> Count;
	for (int i = 1; i <= Count; i++) {
		int a;
		cin >> a;
		if (a != -1) {
			v.push_back(a);
		}
	}
	cin >> x;
	v.push_back(x);

	sort(v.begin(), v.end());

	First(1);
	Second(1);

	return 0;
}