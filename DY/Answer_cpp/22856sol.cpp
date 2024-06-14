#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> *arr;
vector<int> inorderList[100000];
int allRoute = 0;
int lastCount = 0;

void inorder(int x)
{
	if (x != -1)
	{
		inorder(arr[x - 1].first);
		inorderList->push_back(x);
		inorder(arr[x - 1].second);
	}
}

void routeCounting(int y)
{
	if (arr[y - 1].first != -1)
	{
		routeCounting(arr[y - 1].first);
		allRoute += 1;
	}
	if (y == inorderList->back())
	{
		cout << allRoute << endl;
	}
	allRoute += 1;
	if (arr[y - 1].second != -1)
	{
		routeCounting(arr[y - 1].second);
		allRoute += 1;
	}
}

int main(void)
{
	int count;
	cin >> count;
	arr = new pair<int, int>[count];
	for (int i = 0; i < count; i++)
	{
		int parent, left, right;
		cin >> parent >> left >> right;

		arr[parent-1].first = left;
		arr[parent-1].second = right;
	}
	
	inorder(1);
	routeCounting(1);
	
}