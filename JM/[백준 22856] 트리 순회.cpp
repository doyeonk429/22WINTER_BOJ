#include <iostream>
#include <vector>
using namespace std;

struct NUM {
	int num;
	int leftChild;
	int rightChild;
	int isVisited = 0;
};

NUM arr[100001];
int n;
int cnt;
int state = 0;
vector <int> infix_v;

void inorder_edit(NUM arr[], int cur, int& stat) {
	if (arr[cur].leftChild != -1 && arr[arr[cur].leftChild].isVisited == 0) { cnt++; inorder_edit(arr, arr[cur].leftChild, stat); }
	//cout << arr[cur].num;
	if (arr[cur].rightChild != -1 && arr[arr[cur].rightChild].isVisited == 0) { cnt++; inorder_edit(arr, arr[cur].rightChild, stat); }
	if (cur == infix_v.back()) stat = 1;
	if (stat != 1) cnt++;
}

void inorder(NUM arr[], int cur) {
	if (arr[cur].leftChild != -1) inorder(arr, arr[cur].leftChild);
	infix_v.push_back(cur);
	if (arr[cur].rightChild != -1) inorder(arr, arr[cur].rightChild);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		arr[k].num = k;

		int left, right; cin >> left >> right;
		arr[k].leftChild = left;
		arr[k].rightChild = right;
	}

	inorder(arr, 1);
	inorder_edit(arr, 1, state);
	cout << cnt << '\n';
}
