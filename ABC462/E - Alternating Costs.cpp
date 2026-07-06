#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll even_cost(ll x, ll y, ll a, ll b) {
	if (x < y) swap(x, y);
	ll v1 = 2 * min(a, b) * x;
	ll v2 = 2 * min(a, b) * y + (x - y) / 2 * (a + b);
	return min(v1, v2);
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ll x, y, a, b, ans;
		cin >> a >> b >> x >> y;
        if(x<0) x=-x;
        if(y<0) y=-y;
		if ((x + y) % 2 == 0) ans = even_cost(x, y, a, b);
		else {
			ll x1 = x == 0 ? 1 : x - 1, y1 = y == 0 ? 1 : y - 1;
			ans = min(even_cost(x1, y, a, b) + a, even_cost(x, y1, a, b) + b);
		}
		cout << ans << endl;
	}
	return 0;


}