#include <iostream>
using namespace std;

int* arr;
int* tmp;
int n, k, ans = -1;
int cnt = 0;

void merge(int* arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int t = 1;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])  tmp[t++] = arr[i++];
		else tmp[t++] = arr[j++];
	}
	while (i <= mid) tmp[t++] = arr[i++];
	while (j <= end) tmp[t++] = arr[j++];

	i = start; t = 1;
	while (i <= end) {
		arr[i++] = tmp[t++];
		cnt++;
		if (cnt == k) ans = arr[i - 1];
	}
}

void merge_sort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n >> k;
	arr = new int[n + 1];
	tmp = new int[n + 1];
	for (int i = 0; i < n; ++i) cin >> arr[i];

	merge_sort(arr, 0, n - 1);
	cout << ans;
}