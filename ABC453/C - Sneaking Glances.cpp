#include <bits/stdc++.h>
using namespace std;
int n, l[20], ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int mask = 0; mask < (1 << n); mask++) {
		double pos = 0.5;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				if (pos < 0 && 0 < pos + l[i]) cnt++;
				pos += l[i];
			} else {
				if (pos - l[i] < 0 && 0 < pos) cnt++;
				pos -= l[i];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}