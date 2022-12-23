#include <iostream>
using namespace std;

struct alpha {
	char a;
	int leftChild;
	int rightChild;
};

alpha arr[26];

void prefix(alpha arr[], int cur) {
	cout << arr[cur].a;
	if (arr[cur].leftChild != '.' - 65) prefix(arr, arr[cur].leftChild);
	if (arr[cur].rightChild != '.' - 65) prefix(arr, arr[cur].rightChild);
}

void infix(alpha arr[], int cur) {
	if (arr[cur].leftChild != '.' - 65) infix(arr, arr[cur].leftChild);
	cout << arr[cur].a;
	if (arr[cur].rightChild != '.' - 65) infix(arr, arr[cur].rightChild);
}

void postfix(alpha arr[], int cur) {
	if (arr[cur].leftChild != '.' - 65) postfix(arr, arr[cur].leftChild);
	if (arr[cur].rightChild != '.' - 65) postfix(arr, arr[cur].rightChild);
	cout << arr[cur].a;
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		int k = c - 65;
		arr[k].a = c;

		char left, right; cin >> left >> right;
		arr[k].leftChild = left - 65;
		arr[k].rightChild = right - 65;
	}

	prefix(arr, 0);
	cout << '\n';
	infix(arr, 0);
	cout << '\n';
	postfix(arr, 0);
	cout << '\n';
}
