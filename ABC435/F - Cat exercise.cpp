#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int n, a[maxn];
int st[maxn], l[maxn], r[maxn], top;
ll ans[maxn], res;
ll calc(int x) {
	if (ans[x]) return ans[x];
	ll res = 0;
	if (l[x]) res = max(res, calc(l[x]) + abs(x - l[x]));
	if (r[x]) res = max(res, calc(r[x]) + abs(x - r[x]));
	return ans[x] = res;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int k = top;
		while (k && a[st[k]] < a[i]) 
			--k;
		if (k < top) l[i] = st[k + 1];
		if (k) r[st[k]] = i;
		st[++k] = i;
		top = k;
	}
	for (int i = 1; i <= n; i++) res = max(res, calc(i));
	cout << res << endl;
}