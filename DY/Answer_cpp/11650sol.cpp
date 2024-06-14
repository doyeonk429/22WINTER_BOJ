#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sorting(int** data, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (data[i][0] == data[j][0])
			{
				if (data[i][1] > data[j][1])
				{
					int tmp = data[i][1];
					data[i][1] = data[j][1];
					data[j][1] = tmp;
				}
			}
		}
		
	}
}
int main()
{
	int count;
	cin >> count;
	
	vector<pair<int, int>> arr;
	for (int i = 0; i < count; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(pair<int, int>(a, b));
	}
	
	//sorting(arr, count);
	sort(arr.begin(), arr.end());

	for (int i = 0; i < count; i++)
	{
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
	cout << endl;

	return 0;
}