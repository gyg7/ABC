#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5, MOD = 998244353;
int t, n, a[N], b[N];
ll s[N];
int stk[N], top;
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		cin >> n;
		top = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += n - i;
			s[i] = s[i - 1] + a[i];
			while (top) {
				int l = stk[top - 1], m = stk[top], r = i;
				int v1 = (s[m] - s[l] + (m - l - 1)) / (m - l);
				int v2 = (s[r] - s[m]) / (r - m);
				if (v1 <= v2) break;
				--top;
			}
			stk[++top] = i;
		}
		for (int i = 1; i <= top; i++) {
			int len = stk[i] - stk[i - 1];
			int v = (s[stk[i]] - s[stk[i - 1]]) / len;
			int rest = (s[stk[i]] - s[stk[i - 1]]) % len;
			for (int j = stk[i - 1] + 1; j <= stk[i]; j++)
				b[j] = v;
			for (int j = stk[i] - rest + 1; j <= stk[i]; j++) b[j]++;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += 1ll * i * (b[i] - a[i]);
		}
		cout << ans << endl;
	}
}
