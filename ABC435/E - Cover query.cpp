#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int n, q;
struct tree {
	int lc, rc, white;
} tr[20 * N];

int tot = 1;
void push_up(int p) {
	tr[p].white = 0;
	int lc = tr[p].lc, rc = tr[p].rc;
	if (lc) tr[p].white += tr[lc].white;
	if (rc) tr[p].white += tr[rc].white;
}
void update(int p, int pl, int pr, int L, int R) {
	if (L <= pl && pr <= R) {
		tr[p].white = 0;
		return;
	}
	int mid = (pl + pr) / 2;
	int &lc = tr[p].lc, &rc = tr[p].rc;
	if (!lc) tr[lc = ++tot].white = mid - pl + 1;
	if (!rc) tr[rc = ++tot].white =  pr - mid;
	if (!tr[p].white) tr[lc].white = tr[rc].white = 0;
	if (L <= mid) update(lc, pl, mid, L, R);
	if (mid < R) update(rc, mid + 1, pr, L, R);
	push_up(p);
}
int root;
int main() {
	cin >> n >> q;
	tr[1].white = n;
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		update(1, 1, n, l, r);
		cout << tr[1].white << endl;
	}
}