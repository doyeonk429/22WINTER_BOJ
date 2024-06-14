#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<map>
using namespace std;
int n, m;
bool cmp(pair<int, string>x, pair<int, string>y)
{
	if (x.first == y.first) // 빈도 동일할 경우
	{
		if (x.second.length() == y.second.length()) // 단어 길이 동일할 경우
		{
			return x.second < y.second; // 사전 순 정렬
		}
		else
		{
			return x.second.length() > y.second.length(); // 길이 순 정렬
		}
	}
	else
		return x.first > y.first; // 빈도 순 정렬
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