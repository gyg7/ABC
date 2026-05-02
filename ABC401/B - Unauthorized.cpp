#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
bool login;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (s == "login") login = 1;
		if (s == "logout") login = 0;
		if (s == "private") if (!login) cnt++;
	}
	cout << cnt << endl;
	return 0;
}