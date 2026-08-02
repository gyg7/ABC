#include <bits/stdc++.h>
using namespace std;
int n, a[101], cnt[101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (i  <= a[n - i + 1]) {
			cout <<  i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}