#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n, q;
struct point {
	int x, y, id;
} p[N];
int a, b, rnk[N];
int corss(point a, point b) {
	return 1ll * a.x * b.y - 1ll * b.x * a.y;
}
bool cmp(point a, point b) {
	bool ah = (a.y < 0) || (a.y == 0 && a.x < 0);
	bool bh = (b.y < 0) || (b.y == 0 && b.x < 0);
	if (ah != bh) return ah < bh;
	return corss(a, b) > 0;
}
int L[N], R[N];
signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n, cmp);
	reverse(p + 1, p + 1 + n);
	L[1] = 1, R[n] = n;
	for (int i = 2; i <= n; i++) {
		if (!cmp(p[i], p[i - 1])) L[i] = L[i - 1];
		else L[i] = i;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (!cmp(p[i + 1], p[i])) R[i] = R[i + 1];
		else R[i] = i;
	}
	for (int i = 1; i <= n; i++) rnk[p[i].id] = i;
	for (int i = 1; i <= q; i++) {
		cin >> a >> b;
		a = rnk[a], b = rnk[b];
		if (L[a] <= R[b]) cout << (R[b] - L[a] + 1) << endl;
		else cout << n - (L[a] - R[b] - 1) << endl;
	}
}