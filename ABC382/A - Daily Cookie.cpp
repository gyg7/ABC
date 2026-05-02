#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
char ch;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		if (ch == '.') ++cnt;
	}
	cout << cnt + m << endl;
	return 0;
}