#include <bits/stdc++.h>
using namespace std;
#define int long long
string x, y;
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	cin >> x >> y;
}
void solve() {
	if (x == y) puts("Yes");
	else if (x == "Lynx") puts("Yes");
	else if (y == "Lynx") puts("No");
	else if (x == "Serval") puts("Yes");
	else if (y == "Serval") puts("No");
	else if (x == "Ocelot") puts("Yes");
	else if (y == "Ocelot")puts("No");
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();

	}
}
