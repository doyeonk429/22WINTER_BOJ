#include <iostream>
#include <algorithm>
using namespace std;
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

int arr[1001][3];
int arrnew[1001][3];
int main()
{
	TIMME;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++) { cin >> arr[i][j]; }
	}
	for (int i = 1; i <= N; i++)
	{
		arrnew[i][0] = min(arrnew[i - 1][1], arrnew[i - 1][2]) + arr[i][0];
		arrnew[i][1] = min(arrnew[i - 1][0], arrnew[i - 1][2]) + arr[i][1];
		arrnew[i][2] = min(arrnew[i - 1][0], arrnew[i - 1][1]) + arr[i][2];
	}
	int a, b, c;
	a = arrnew[N][0];	b = arrnew[N][1];	c = arrnew[N][2];
	cout << min({a,b,c}) << '\n';
}