#include <bits/stdc++.h>
using namespace std;
int n, a[110], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i < n; i++) {
		if (a[i - 1] < a[i] && a[i] > a[i + 1]) ++ans;
	}
	cout << ans << endl;
	return 0;
}