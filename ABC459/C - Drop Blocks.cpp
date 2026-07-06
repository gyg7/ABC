#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>
using namespace std;
#define N 300001
int n, q, opt, v, cnt[N], de;

int main() {
	cin >> n >> q;
	atcoder::fenwick_tree<int> fwt(N + 10);
	for (int i = 1; i <= n; i++) {
		fwt.add(0, 1);
	}
	for (int i = 1; i <= q; i++) {
		cin >> opt >> v;
		if (opt == 1) {

			fwt.add(cnt[v], -1);
			fwt.add(++cnt[v], 1);
			if (fwt.sum(de, de + 1) == 0) de++;
		} else cout << fwt.sum(v + de, N) << endl;
	}
}
