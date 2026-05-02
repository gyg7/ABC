#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, opt, cnt;
char c;
char st[800010];
int s[800010], top;
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
	cin >> q;
}
void solve() {
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 2) {
			if (st[top] == '(')
				cnt--;
			else cnt++;
			top--;

		} else {
			cin >> c;
			if (c == '(') cnt++;
			else cnt--;
			st[++top] = c;
			s[top] = s[top - 1] + (cnt < 0);
		}
		if (cnt == 0 && !s[top]) puts("Yes");
		else puts("No");
	}
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
