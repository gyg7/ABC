#include <bits/stdc++.h>
using namespace std;
int n, a[51], s[51];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int res = s[j] - s[i - 1];
			bool p = 1;
			for (int k = i; k <= j; k++)
				if (res % a[k] == 0) p = 0;
			if (p) ans++;
		}
	}
	cout << ans << endl;
}