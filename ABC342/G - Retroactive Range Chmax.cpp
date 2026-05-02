#include <bits/stdc++.h>
using namespace std;
#define son int p=1,int pl=1,int pr=n
#define lson p*2,pl,mid
#define rson p*2+1,mid+1,pr
int n, q, cmd, l[2000001], r[2000001], x[2000001], k;
struct node {
	priority_queue <int> p, d;
	void push(int x) {
		p.push(x);
	}
	void easer(int x) {
		d.push(x);
	}
	int top() {
		while (!d.empty() && !p.empty() && d.top() == p.top()) {
			d.pop();
			p.pop();
		}
		return p.empty() ? 0 : p.top();
	}
} t[800000];
void build(son) {
	if (pl == pr) {
		int x;
		cin >> x;
		t[p].push(x);
		return ;
	}
	int mid = (pl + pr) / 2;
	build(lson);
	build(rson);
}
void update(int l, int r, int x, int type, son) {
	if (l <= pl && pr <= r) {
		if (type == 1)t[p].push(x);
		else t[p].easer(x);
		return ;
	}
	if (pr < l || r < pl) return;
	int mid = (pl + pr) / 2;
	update(l, r, x, type, lson);
	update(l, r, x, type, rson);
}
int query(int x, son) {
	if (pl == pr) return t[p].top();
	int res = t[p].top();
	int mid = (pl + pr) / 2;
	if (x <= mid) res = max(res, query(x, lson));
	else res = max(res, query(x, rson));
	return res;
}
int main() {
	cin >> n;
	build();
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> l[i] >> r[i] >> x[i];
			update(l[i], r[i], x[i], 1);
		}
		if (cmd == 2) {
			cin >> k;
			update(l[k], r[k], x[k], 0);
		}
		if (cmd == 3) {
			cin >> k;
			cout << query(k) << endl;
		}
	}
}