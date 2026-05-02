#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int n, t, a[200001];
int vis[2001][2001];
int   k[2001][2001];
int lowbit(int x) {
	return x & -x;
}
void add(int x, int y, int v) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			vis[i][j] += v;
}
int query(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			res += vis[i][j];
	return res;
}
int query(int x1, int y1, int x2, int y2) {
	return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
bool check() {
	rep(i, 1, n) {
		if (query(i, 1, i, n) == n) return 1;
		if (query(1, i, n, i) == n) return 1;
	}
	int ok = 0;
	rep(i, 1, n) if (ok |= (k[i][i] == 0)) break;
	if (ok == 0) return 1;
	ok = 0;
	rep(i, 1, n) if (ok |= (k[n - i + 1][i] == 0)) break;
	if (ok == 0) return 1;
	return 0;
}
int l, r, ans = -1;
int main() {
	cin >> n >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}
	l = n;
	r = t;
	while (l <= r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= mid; i++) {
			add((a[i] - 1) / n + 1, (a[i] - 1) % n + 1, 1);
			k[(a[i] - 1) / n + 1][(a[i] - 1) % n + 1] = 1;
		}
		if (check()) {
			ans = mid;
			r = mid - 1;
		} else
			l = mid + 1;
		for (int i = 1; i <= mid; i++) {
			add((a[i] - 1) / n + 1, (a[i] - 1) % n + 1, -1);
			k[(a[i] - 1) / n + 1][(a[i] - 1) % n + 1] = 0;
		}
	}
	cout << ans << endl;
}