#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int n, l, d[N], pos[N];
int cnt[N];
int main() {
	cin >> n >> l;
	for (int i = 1; i < n; i++) {
		cin >> d[i];
	}
	if (l % 3) {
		puts("0");
        return 0;
	}
	int step = l / 3;
    long long ans = 0;
	pos[1] = 0;
	for (int i = 2; i <= n; i++) {
		pos[i] = (pos[i - 1] + d[i - 1]) % l;
	}
	d[0] = l - pos[n];
	for (int i = n + 1; i <= 2 * n; i++) {
		pos[i] = (pos[i - 1] + d[i - n - 1]) % l;
	}

	for (int a = 1; a <= n; a++) {
		cnt[pos[a]]++;
	}
	for (int i = 1; i <= n; i++) {
		long long mul = 1ll*cnt[(pos[i] + step) % l] * cnt[(pos[i] + 2 * step) % l];
		ans += mul;
	}
	cout << ans/3 << endl;
	return 0;
}