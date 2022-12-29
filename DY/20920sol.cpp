#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<map>
using namespace std;
int n, m;
bool cmp(pair<int, string>x, pair<int, string>y)
{
	if (x.first == y.first) // �� ������ ���
	{
		if (x.second.length() == y.second.length()) // �ܾ� ���� ������ ���
		{
			return x.second < y.second; // ���� �� ����
		}
		else
		{
			return x.second.length() > y.second.length(); // ���� �� ����
		}
	}
	else
		return x.first > y.first; // �� �� ����
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	map<string, int> wordList;
	cin >> n >> m;

	while (n--)
	{
		string str; cin >> str;
		if (str.length() >= m)
		{
			wordList[str]++;
		}
	}

	vector<pair<int, string>> book;
	for (auto w : wordList)
		book.push_back({ w.second, w.first });
	sort(book.begin(), book.end(), cmp);
	for (auto v : book)
		cout << v.second << "\n";
	cout << endl;
	return 0;
}