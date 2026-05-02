#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<int> a;

int f(vector<int> A, int M, int k) {
	if (k == 0) return 0;
	vector<int> B[2];
	for (int i : A) {
		B[(i >> (k - 1)) & 1].push_back(i & ~(1 << (k - 1)));
	}
	int mid = 1 << (k - 1);
	if (M == 1 << k) {
		if (!B[0].empty() && !B[1].empty()) {
			return f(B[0], mid, k - 1) + f(B[1], mid, k - 1);
		}
		return 2 * f(A, mid, k - 1) + mid * mid;
	}
	int ans = B[0].empty() ? f(A, min(M, mid), k - 1) + mid * min(M, mid)
	          : f(B[0], min(M, mid), k - 1);
	if (M > mid) {
		ans += B[1].empty() ? f(A, M - mid, k - 1) + mid * (M - mid)
		       : f(B[1], M - mid, k - 1);
	}
	return ans;
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
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
	cout << f(a, m, 30) << '\n';
}

signed main() {
	int t = 1;
//	cin>>t;
	pre();
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}