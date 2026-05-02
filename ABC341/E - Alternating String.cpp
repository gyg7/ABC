#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
#define son int p = 1,int pl = 1,int pr = n
#define lson p*2,pl,mid
#define rson p*2+1,mid+1,pr
int n, q, cmd, l, r;
string s;
struct node {
	int l, r, tag;
	bool have;
	void save() {
		tag ^= 1;
		l ^= 1;
		r ^= 1;
	}
} tr[4 * N], uy[4];
void push_up(node tr[], int p) {
	tr[p].l = tr[2 * p].l;
	tr[p].r = tr[2 * p + 1].r;
	tr[p].have = tr[2 * p].r == tr[2 * p + 1].l;
	tr[p].have |= tr[p * 2].have;
	tr[p].have |= tr[p * 2 + 1].have;
}
void push_down(int p) {
	if (tr[p].tag == 0) return;
	tr[p * 2].save();
	tr[p * 2 + 1].save();
	tr[p].tag = 0;
}
void build(son) {
	if (pl == pr) {
		tr[p].l = tr[p].r = s[pl - 1] == '1';
		return ;
	}
	int mid = (pl + pr) / 2;
	build(lson);
	build(rson);
	push_up(tr, p);
}
void update(int l, int r, son) {
	if (l <= pl && pr <= r) {
		tr[p].save();
		return ;
	}
	if (pr < l || r < pl)
		return;
	int mid = (pl + pr) / 2;
	push_down(p);
	update(l, r, lson);
	update(l, r, rson);
	push_up(tr, p);
}
node query(int l, int r, son) {
	if (pr < l || r < pl)
		return {INT_MIN, INT_MAX, 0};
	if (l <= pl && pr <= r)
		return tr[p];

	int mid = (pl + pr) / 2;
	push_down(p);
	node ls = query(l, r, lson);
	node rs = query(l, r, rson);
	uy[2] = ls;
	uy[3] = rs;
	push_up(uy, 1);
	return uy[1];
}
int main() {
	cin >> n >> q >> s;
	build();
	for (int i = 1; i <= q; i++) {
		cin >> cmd >> l >> r;
		if (cmd == 1)
			update(l, r);
		if (cmd == 2) {
			node res = query(l, r);
			if (res.have)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
}