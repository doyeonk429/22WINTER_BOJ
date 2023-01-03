#include <iostream>
#include <vector>
using namespace std;

int n, r, q;

struct nodeInfo {
	int level = 999999;
	vector <int> link;
};

void makeTree(nodeInfo* nodes, int cur) {
	for (int i = 0; i < nodes[cur].link.size(); ++i) {
		int next = nodes[cur].link[i];
		if (nodes[next].level > nodes[cur].level) {
			nodes[next].level = nodes[cur].level + 1;
			makeTree(nodes, next);
		}
	}
}

int arr[100001];
int search(nodeInfo* nodes, int k) {
	if (arr[k] == 0) {
		int ret = 1;
		for (int i = 0; i < nodes[k].link.size(); ++i) {
			if (nodes[nodes[k].link[i]].level > nodes[k].level) {
				ret = ret + search(nodes, nodes[k].link[i]);
			}
		}
		arr[k] = ret;
		return ret;
	}
	else return arr[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> q;
	nodeInfo* nodes = new nodeInfo[n+1];

	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		nodes[a].link.push_back(b);
		nodes[b].link.push_back(a);
	}

	nodes[r].level = 1;
	makeTree(nodes, r);

	for (int i = 0; i < q; ++i) {
		int k; cin >> k;
		cout << search(nodes, k) << '\n';
	}
}