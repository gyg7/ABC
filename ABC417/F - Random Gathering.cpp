#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5 + 1;
ll ksm(ll x, int y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int n, m, l, r;
ll x[N], tag[N], sum[N];
int st[N], ed[N], idx[N], block, tot;
void push_down(int m) {
	if (!tag[m]) return;
	for (int i = st[m]; i <= ed[m]; i++)
		x[i] = tag[m];
	tag[m] = 0;
}
void update(int l, int r, ll v) {
	int p = idx[l], q = idx[r];
	push_down(p);
	push_down(q);
	if (p == q) {
		for (int i = l; i <= r; i++) {
			sum[p] = ((sum[p] - x[i] + v) % mod + mod) % mod;
			x[i] = v;
		}
		return;
	}
	for (int i = l; i <= ed[p]; i++) {
		sum[p] = ((sum[p] - x[i] + v) % mod + mod) % mod;
		x[i] = v;
	}
	for (int i = st[q]; i <= r; i++) {
		sum[q] = ((sum[q] - x[i] + v) % mod + mod) % mod;
		x[i] = v;
	}
	for (int i = p + 1; i < q; i++) {
		sum[i] = (v * (ed[i] - st[i] + 1)) % mod;
		tag[i] = v;
	}
}
ll getsum(int l, int r) {
	int p = idx[l], q = idx[r];
	push_down(p);
	push_down(q);
	if (p == q) {
		ll Sum = 0;
		for (int i = l; i <= r; i++) (Sum += x[i]) %= mod;
		return Sum;
	}
	ll Sum = 0;
	for (int i = l; i <= ed[p]; i++) (Sum += x[i]) %= mod;
	for (int i = st[q]; i <= r; i++) (Sum += x[i]) %= mod;
	for (int i = p + 1; i < q; i++) (Sum += sum[i]) %= mod;
	return Sum;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	block = sqrt(n), tot = (n + block - 1) / block;
	for (int i = 1; i <= tot; i++) {
		st[i] = (i - 1) * block + 1;
		ed[i] = min(i * block, n);
		for (int j = st[i]; j <= ed[i]; j++) {
			sum[i] = (sum[i] + x[j]) % mod;
			idx[j] = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> l >> r;
		update(l, r, (getsum(l, r)*ksm(r - l + 1, mod - 2)) % mod);
	}
	for (int i = 1; i <= n; i++)
		cout << getsum(i, i) << " ";
	return 0;
}