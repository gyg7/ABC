#include <bits/stdc++.h>
using namespace std;
int n, a[300001];
long long ans, sum;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans = ans + sum * a[i];
		sum = sum + a[i];
	}
	cout << ans << endl;
	return 0;
}
