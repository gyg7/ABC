#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, s[200001];
signed main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		if (n == 2 && s[1] * 2 >= s[2]) {
			cout << 2 << endl;
		} else if (n == 2) {
			cout << -1 << endl;
		} else {
			sort(s + 2, s + n);
			int last = 1, cnt = 1;
			while (last != n) {
				int val = 2 * s[last], p = 0, now = last;
                if(val>=s[n]){cnt++;last=n;break;}
				for (int i = 28; i >= 0; i--) {
					if (now + (1ll << i) <= n && val >= s[now + (1ll << i)]) {
						now = now + (1ll << i);
						p = 1;
					}

				}
				if (p) {
					last = now;
					cnt++;
				} else break;
			}
			if (last == n)
				cout << cnt << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
