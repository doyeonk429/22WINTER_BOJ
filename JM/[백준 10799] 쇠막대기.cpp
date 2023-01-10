#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<char> s;
	string input; cin >> input;
	char c;
	int cnt = 0;

	s.push(input[0]);
	for (int i = 1; i < input.size(); ++i) {
		if (input[i] == '(') s.push(input[i]);
		else if (input[i] == ')') {
			if (input[i - 1] == '(') {
				s.pop();
				cnt += s.size();
			}
			else if (input[i-1] == ')') {
				s.pop();
				cnt++;
			}
		}
	}

	cout << cnt;
}