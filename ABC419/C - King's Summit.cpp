#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, r[200001], c[200001];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> r[i] >> c[i];
	sort(r + 1, r + 1 + n);
	sort(c + 1, c + 1 + n);
	cout << max(r[n] - r[1]+1, c[n] - c[1]+1) / 2 << endl;
	return 0;
}

