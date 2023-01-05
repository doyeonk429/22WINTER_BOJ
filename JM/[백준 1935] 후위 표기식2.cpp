#include <iostream>
#include <string>
#include <stack>
using namespace std;

double arr[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	stack<double> st;
	int cnt;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			// 피연산자 만난 경우
			cnt = s[i] - 'A';
			st.push(arr[cnt]);
		}
		else {
			// 연산자 만난 경우
			double tmp;
			double num2 = st.top(); st.pop();
			double num1 = st.top(); st.pop();

			if (s[i] == '+') tmp = num1 + num2;
			else if (s[i] == '-') tmp = num1 - num2;
			else if (s[i] == '*') tmp = num1 * num2;
			else if (s[i] == '/') tmp = num1 / num2;

			st.push(tmp);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();
}