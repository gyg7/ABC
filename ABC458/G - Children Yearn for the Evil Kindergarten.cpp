#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
const int N = 3e5+10;
const int lim = 0x3f3f3f3f;
int n, a[N], b[N], c[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int s = 0;
	for (int i = n; i >= 1; i--) {
		pq.push(pii(c[i] - s, lim));
		s += b[i];
		int x = 0, y = -a[i];
		while (y < 0) {
			int u = pq.top().first;
			int v = pq.top().second;
			pq.pop();
			u += s;
			__int128 all = (__int128)(u * v);
			if ((__int128)y + all < 0) {
				x += v;
				y += all;
			} else {
				int ad = (-y) / u;
				x += ad;
				y += u * ad;
				u -= s;
				v -= ad;
				if (!y) {
					if (v) pq.push(pii(u, v));
				} else {
					v--;
					if (v) pq.push(pii(u, v));
					pq.push(pii(u + y, 1));
					y = 0;
				}
			}
		}
		pq.push(pii(-s, x));
	}
	cout << pq.top().second << endl;
}
signed main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}