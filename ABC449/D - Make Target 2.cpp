#include <bits/stdc++.h>
using namespace std;
int l, r, u, d;
int main() {
	cin >> l >> r >> u >> d;
	int D = max({abs(l), abs(r), abs(u), abs(d)});
	long long ans = 0;
    if(l<=0&&0<=r&&u<=0&&0<=d) ans++;
	for (int i = 1; 2 * i <= D; i++) {
		int k = 2 * i;
        long long res = 0;
		if (l <= k && k <= r)
			res += max(0, min(d, k) - max(u, -k) + 1);
		if (l <= -k && -k <= r)
			res += max(0, min(d, k) - max(u, -k) + 1);
		if (u <= k && k <= d)
			res += max(0, min(r, k - 1) - max(l, - k + 1) + 1);
		if (u <= -k && -k <= d)
			res += max(0, min(r, k - 1) - max(l, - k + 1) + 1);
		ans += res;
	}
	cout << ans << endl;
}