#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans;
typedef pair<int, int> pii;
set<pii> se;
bool find(int x, int y) {
	if (se.find({x, y}) != se.end()) return true;
	if (se.find({x + 1, y}) != se.end()) return true;
	if (se.find({x, y + 1}) != se.end()) return true;
	if (se.find({x + 1, y + 1}) != se.end()) return true;
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (find(x, y) == 0) {
			ans++;
			se.insert({x, y});
			se.insert({x, y + 1});
			se.insert({x + 1, y});
			se.insert({x + 1, y + 1});
		}
	}
	cout << ans << endl;
}