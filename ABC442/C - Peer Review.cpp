#include <bits/stdc++.h>
using namespace std;
long long n, cnt[200001], m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		cnt[x]++;
		cnt[y]++;
	}
	for (int i = 1; i <= n; i++) {
		long long ans = (n - cnt[i]-1) * (n - cnt[i] - 2) / 2 * (n - cnt[i] - 3) / 3;
		cout << ans << " ";
	}
}