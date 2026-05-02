#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 1;
int n, q;
struct node {
	int w, v;
} p[N];
struct Ask {
	int l, r, c, id;
} tmp;
vector<Ask> A;
int ans[10 * N];
void chkmax(int &x, int y) {
	if (x < y) x = y;
}
int L[N][501] = {0}, R[N][501] = {0}, tmpl[501], tmpr[501];
void work(const vector<Ask> &ve, int l, int r) {
	if (l == r) {
		for (auto item : ve)
			ans[item.id] = (item.c >= p[l].w ? p[l].v : 0);
		return;
	}
	vector<Ask> lq, rq;
	int mid = (l + r) / 2;
	for (int i = l; i <= mid + 1; i++)
		for (int j = 0; j <= 500; j++)
			L[i][j] = 0;
	for (int i = mid; i <= r; i++)
		for (int j = 0; j <= 500; j++)
			R[i][j] = 0;
	for (int i = mid; i >= l; i--)
		for (int j = 0; j <= 500; j++) {
			L[i][j] = L[i + 1][j];
			if (j >= p[i].w) {
				chkmax(L[i][j], L[i + 1][j - p[i].w] + p[i].v);
			}
		}
	for (int i = mid + 1; i <= r; i++)
		for (int j = 0; j <= 500; j++) {
			R[i][j] = R[i - 1][j];
			if (j >= p[i].w)
				chkmax(R[i][j], R[i - 1][j - p[i].w] + p[i].v);
		}
	for (auto item : ve) {
		if (item.r <= mid) lq.push_back(item);
		else if (mid < item.l) rq.push_back(item);
		else {
			for (int i = 0; i <= 500; i++) {
				tmpl[i] = L[item.l][i];
				tmpr[i] = R[item.r][i];
			}
			for (int i = 1; i <= 500; i++) {
				chkmax(tmpl[i], tmpl[i - 1]);
				chkmax(tmpr[i], tmpr[i - 1]);
			}
			int best = 0;
			for (int i = 0; i <= item.c; i++)
				chkmax(best, tmpl[i] + tmpr[item.c - i]);
			ans[item.id] = best;
		}
	}
	work(lq, l, mid);
	work(rq, mid + 1, r);
}
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
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].w >> p[i].v;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> tmp.l >> tmp.r >> tmp.c;
		tmp.id = i;
		A.push_back(tmp);
	}
}
void solve() {
	work(A, 1, n);
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
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