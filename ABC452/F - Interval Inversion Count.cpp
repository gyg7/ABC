#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
ll n, k, a[N];
struct bit {
	int a[N];
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x, int v) {
		for (int i = x; i <= n; i += lowbit(i))
			a[i] += v;
	}
	int query(int x) {
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += a[i];
		return res;
	}
	void clear() {
		memset(a, 0, sizeof(a));
	}
} t;
int r1[N];
ll slove(ll k) {
	ll ans = 0;
	int r = 1;
	ll cur = 0;
	for (int l = 1; l <= n; l++) {
		while (r <= n && cur + t.query(n) - t.query(a[r]) <= k) {
			cur += t.query(n) - t.query(a[r]);
			t.add(a[r], 1);
			r++;
		}
		ans += r - l;
		cur -= t.query(a[l] - 1);
		t.add(a[l], -1);
	}
	return ans;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << slove(k) - (k ? slove(k - 1) : 0) << endl;
	return 0;
}