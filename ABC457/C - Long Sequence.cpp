#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+100;
int n, c[N], l[N], a[N], sum[N];
long long k;
signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
		sum[i] = sum[i - 1] + l[i];
		for (int j = 1; j <= l[i]; j++) {
			cin >> a[sum[i - 1] + j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	long long skip = 0;
	for (int i = 1; i <= n; i++) {
		if (k - skip > c[i]*l[i]) {
			skip += c[i] * l[i];
		} else {
			long long p = (k - skip - 1) % l[i] + 1;
			cout << a[sum[i - 1] + p] << endl;
			break;
		}
	}
}