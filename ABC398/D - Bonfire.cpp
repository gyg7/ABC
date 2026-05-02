#include <bits/stdc++.h>
using namespace std;
int n, r, c, ans, dx, dy;
string s;
set<pair<int, int>> se, tmp;
int main() {
	cin >> n >> r >> c >> s;
	s = " " + s;
	se.insert({0, 0});
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'N') dx--;
		if (s[i] == 'S') dx++;
		if (s[i] == 'W') dy--;
		if (s[i] == 'E') dy++;
		se.insert({-dx, -dy});
		if (se.count({r - dx, c - dy})) cout << 1;
		else cout << 0;
	}
	return 0;
}