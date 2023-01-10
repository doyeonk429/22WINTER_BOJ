#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int len, temp;
bool MINUS;
int sum = 0;
char str[51];

int main()
{

	cin >> str;
	len = strlen(str); 
	for (int i = 0; i <= len; i++)
	{
		if (str[i] == '+' || str[i] == '-' || i == len)
		{
			if (MINUS == false) 
			{
				sum += temp;
				temp = 0;
			}
			else
			{
				sum -= temp;
				temp = 0;
			}
			if (str[i] == '-') MINUS = true;
		}
		else
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}
	cout << sum;
}