#include <bits/stdc++.h>
using namespace std;
int n, m, a[11], b[11];
string s[200010];
vector<int> ve[11];
int allow[200010][11];
void solve(int id) {
	int sz = s[id].length();
	if (sz != n) {
		puts("No");
		return;
	}
	for (int j = 0; j < sz; j++) {
		if (!(allow[a[j]][b[j] - 1] & (1 << (s[id][j] - 'a')))) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		int sz = s[i].length();
		ve[sz].push_back(i);
		for (int j = 0; j < sz; j++)
			allow[sz][j] |= (1 << (s[i][j] - 'a'));
	}
	for (int i = 1; i <= m; i++) {
		solve(i);
	}
}