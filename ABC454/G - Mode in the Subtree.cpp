#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e6 + 10;
const int mod = 998244353;
int n, seed, m, f, p[N], c[N];
int sz[N], wc[N];
vector<int> ve[N];
int cnt[N], mx, mxcnt;
int ans;
void add(int c) {
	cnt[c]++;
	if (cnt[c] > mx) {
		mx = cnt[c];
		mxcnt = 1;
	} else if (mx == cnt[c]) mxcnt++;
}
void adddfs(int u) {
	add(c[u]);
	for (int v : ve[u]) adddfs(v);
}
void clrdfs(int u) {
	cnt[c[u]] = 0;
	for (int v : ve[u]) clrdfs(v);
}
void dfs(int u, int clear) {
	for (int v : ve[u]) {
		if (v == wc[u]) continue;
		dfs(v, 1);
	}
	if (wc[u])
		dfs(wc[u], 0);
	for (int v : ve[u]) {
		if (v == wc[u]) continue;
		adddfs(v);
	}
	add(c[u]);
	(ans += 1ll * (mx ^ u) * (mxcnt ^ u) % mod) %= mod;
    if(clear){mx=0,mxcnt=0;clrdfs(u);}
}
int main() {
	cin >> n >> seed >> m >> f;
	for (int i = 2; i <= n; i++) {
		if (i <= m) cin >> p[i];
		else {
			p[i] = (seed % (i - 1)) + 1;
			seed = (seed * 1103515245ll + 12345) % 2147483648;
		}
	}
	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
		if (i <= m) cin >> c[i];
		else {
			c[i] = seed % f + 1;
			seed = (seed * 1103515245ll + 12345) % 2147483648;
		}
	}
	for (int i = n; i >= 1; i--) {
		sz[p[i]] += sz[i];
		if (sz[wc[p[i]]] < sz[i]) wc[p[i]] = i;
		ve[p[i]].push_back(i);
	}
	dfs(1, 0);
    cout<<ans<<endl;
}