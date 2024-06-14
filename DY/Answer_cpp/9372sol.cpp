#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//무조건 mst?
int T, N, M;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < M; j++)
		{
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}
