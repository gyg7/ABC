#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 998244353;
int t;
ll A, B, X, Y;
ll v_0, v_1, v_2, v_3;
ll ans;
int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}
void update(ll x, ll y) {
	ll f0 = 2 * B * x + v_0, f1 = 2 * A * y + v_1;
	ll f2 = 2 * A * x + v_2, f3 = 2 * B * y + v_3;
	ans = min(ans, max(abs(f0), abs(f1)) + max(abs(f2), abs(f3)));
}
ll flr(ll a, ll b) {
	if (b < 0) a = -a, b = -b;
	if (a >= 0) return a / b;
	return -((-a + b - 1) / b);
}
void solve(ll a00, ll a01, ll b0, ll a10, ll a11, ll b1) {
	ll det = a00 * a11 - a01 * a10;
	if (!det) return;
	ll nx = b0 * a11 - a01 * b1, ny = a00 * b1 - b0 * a10;
	ll x0 = flr(nx, det), y0 = flr(ny, det);
	for (int i = -3; i <= 3; i++)
		for (int j = -3; j <= 3; j++)
			update(x0 + i, y0 + j);
}
void work() {
	int d, x0, y0;
	d = exgcd(A, B, x0, y0);

	if (X % d || Y % d) {
		puts("-1");
		return;
	}
	A /= d, B /= d, X /= d, Y /= d;
	ans = 9e18;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			ll cx = X - i * A - j * B, cy = Y - i * B - j * A;
			if ((cx % 2) || (cy % 2)) continue;
			ll v0 = cx / 2 * x0;
			ll v1 = cx / 2 * y0;
			ll v2 = cy / 2 * y0;
			ll v3 = cy / 2 * x0;

			v_0 = 2 * v0 + i;
			v_1 = 2 * v2 + i;
			v_2 = -2 * v1 - j;
			v_3 = -2 * v3 - j;
			solve(2 * B, -2 * A, v_1 - v_0, 2 * B, 2 * A, -v_1 - v_0);
			solve(2 * A, -2 * B, v_3 - v_2, 2 * A, 2 * B, -v_3 - v_2);
			solve(2 * B, -2 * A, v_1 - v_0, 2 * A, 2 * B, -v_3 - v_2);
			solve(2 * A, -2 * B, v_3 - v_2, 2 * B, 2 * A, -v_1 - v_0);
			solve(2 * B, -2 * A, v_1 - v_0, 2 * A, 2 * B, v_3 - v_2);
			solve(2 * B, -2 * A, -v_1 - v_0, 2 * A, 2 * B, -v_3 - v_2);
		}
	}
	if (ans == (ll)(9e18)) cout << -1 << endl;
	else cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> A >> B >> X >> Y;
		work();
	}
}
