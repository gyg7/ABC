#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
#define int long long 
ll n, a, b, d, la;
int m, tot, pos[N];
struct Node {
	ll a, d;
} p[N];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (a <= n) {
			p[++tot] = {a, a - b};
		}
	}
	sort(p + 1, p + 1 + tot, [](Node a, Node b) {
		return a.a < b.a;
	});
	ll ans = 0;
	pos[1] = 1;
	for (int i = 2; i <= tot; i++) {
		pos[i] = i;
		if (p[pos[i - 1]].d < p[pos[i]].d) pos[i] = pos[i - 1];
	}
	int j = tot;
	while (n >= p[1].a) {
		while (j && p[j].a > n) j--;
		if (!j) break;
		ll d = p[pos[j]].d,a = p[pos[j]].a;
		ll t = (n-a)/d+1;
		n-=t*d;
		ans+=t;
	}
	cout << ans << endl;
	return 0;
}