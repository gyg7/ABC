#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
//                U   L  D  R
int T = 1;
int rt, ct, ra, ca;
int n, m, l;
struct node {
	char s;
	int num;
} a[100001], b[100001];
int turn(char c) {
	if (c == 'U') return 0;
	if (c == 'L') return 1;
	if (c == 'D') return 2;
	if (c == 'R') return 3;
}
int cnt, ans;
void solve() {
	cin >> rt >> ct >> ra >> ca;
	cin >> n >> m >> l;
	for (int i = 1; i <= m; i++)
		cin >> a[i].s >> a[i].num;
	for (int i = 1; i <= l; i++)
		cin >> b[i].s >> b[i].num;
	int i = 1, j = 1, posa = 0, posb = 0;
	while (i <= m && j <= l) {
		int nxt = min(a[i].num  - posa, b[j].num - posb);
		posa += nxt, posb += nxt;
		if (a[i].s == b[j].s) {
			if (rt == ra && ct == ca)
				ans += nxt;
		} else {
			int R = rt - ra, C = ct - ca;
			int Dx = dx[turn(b[j].s)] - dx[turn(a[i].s)], Dy = dy[turn(b[j].s)] - dy[turn(a[i].s)];
			int step = -1;
			if (R || C) {
				if (Dx) step = R / Dx;
				if (Dy) step = C / Dy;
				if (0 < step && step <= nxt && Dx * step == R && Dy * step == C) ans++;
			}
		}
		rt += nxt * dx[turn(a[i].s)];
		ct += nxt * dy[turn(a[i].s)];
		ra += nxt * dx[turn(b[j].s)];
		ca += nxt * dy[turn(b[j].s)];
		if (posa == a[i].num) {
			i++;
			posa = 0;
		}
		if (posb == b[j].num) {
			j++;
			posb = 0;
		}
	}
cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}

