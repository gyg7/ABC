#include <bits/stdc++.h>
using namespace std;
int t, n, d, a[200001], b[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		int j = 1, sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			int rem = b[i];
			while (j<=n&&a[j] <= rem) {
				rem -= a[j];
				++j;
			}
			a[j] -= rem;
			sum -= b[i];
			while (j <= i - d) {
				sum -= a[j];
				j++;
			}
		}
		cout << sum << endl;
	}
}