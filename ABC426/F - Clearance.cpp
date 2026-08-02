#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 1;
const int inf = 1e18;
/*线段树*/
struct tree {
	int ls, rs, tag, minv, ps;
#define ls tr[p].ls
#define rs tr[p].rs
#define son int p,int pl,int pr
#define mid (pl+pr)/2
#define lson ls,pl,mid
#define rson rs,mid+1,pr
	void make(int x) {
		if (ps == 0) return;
		tag += x;
		minv -= x;
	}
} tr[2 * N];
int tot, n, a[N], q, l, r,k;
void push_down(int p) {
	int &x = tr[p].tag;
	if (x) {
		tr[ls].make(x);
		tr[rs].make(x);
		x = 0;
	}
}
void push_up(int p) {
	tr[p].minv = min(tr[ls].minv, tr[rs].minv);
	tr[p].ps = tr[ls].ps + tr[rs].ps;
}
int build(int pl, int pr) {
	int p = ++tot;
	if (pl == pr) {
		tr[p].minv = a[pl];
		tr[p].ps = 1;
		return p;
	}
	ls = build(pl, mid);
	rs = build(mid + 1, pr);
	push_up(p);
	return p;
}
int modify(son, int L, int R, int tv) {
	if (tr[p].ps == 0) return 0;
	if (L <= pl && pr <= R && tr[p].minv > tv) {
		tr[p].make(tv);
		return tr[p].ps * tv;
	}
	if (pl == pr) {
		tr[p].ps = 0;
		int ret = tr[p].minv;
		tr[p].minv = inf;
		tr[p].tag = 0;
		return ret;
	}
	push_down(p);
	int ret = 0;
	if (L <= mid) ret += modify(lson, L, R, tv);
	if (mid < R) ret += modify(rson, L, R, tv);
	push_up(p);
	return ret;
}

/*基本骨架*/

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

}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, n);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin>>l>>r>>k;
		cout<<modify(1,1,n,l,r,k)<<endl;
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
