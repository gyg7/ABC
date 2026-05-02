#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull P = 1e7 + 7;
int n, ans, minor;
struct point {
	int x, y;
} p[2001];
unordered_map<ull, int> mp, mp1;
int gcd(int n, int m) {
	if (!m) return n;
	return gcd(m, n % m);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			int dx = p[i].x - p[j].x;
			int dy = p[i].y - p[j].y;
			int d = gcd(dx, dy);
			dx /= d, dy /= d;
			if (!dx) dy = 1;
			ans += mp[dx * P + dy]++;
			minor += mp1[(p[i].x + p[j].x) * (2 * P + 1) + (p[i].y + p[j].y)]++;
		}
	cout << ans - minor << endl;
	return 0;
}
