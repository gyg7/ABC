#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
//#include
using namespace std;
using namespace atcoder;
const int N = 3e5;
int n, q, Lr[N], Lc[N], lnsr[N], lnsc[N];
int e() {
	return 0;
}
int op(int a, int b) {
	return a + b;
}
int maping(int f, int a) {
	return a + f;
}
int com(int a, int b) {
	return a + b;
}
int main() {
	cin >> n >> q;
	lazy_segtree<int, op, e, int, maping, com, e> lastc(q + 1), lastr(q + 1);
	int ans = 0;
	lastc.apply(0, 1, n);
	lastr.apply(0, 1, n);
	for (int i = 1; i <= q; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int r;
			cin >> r;
			ans += lastc.prod(0, i) - lastc.prod(0, Lr[r]);
			lastr.apply(Lr[r], Lr[r] + 1, -1);
			Lr[r] = i;
			lastr.apply(i, i + 1, 1);
		} else {
			int c;
			cin >> c;
			ans += lastr.prod(i + 1, q + 1) - lastr.prod(Lc[c] + 1, q + 1);
			lastc.apply(Lc[c], Lc[c] + 1, -1);
			Lc[c] = i;
			lastc.apply(i, i + 1, 1);
		}

//		for (int r = 1; r <= n; r++)
//			for (int c = 1; c <= n; c++)
//				if (lastc[c] < lastr[r]) ans++;
		cout << ans << endl;
	}
}
