#include <bits/stdc++.h>
using namespace std;
const int N = 800001;
int n, ans[N], pref[N];
char s[N];
int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++) {
		int x = s[i] == 'o';
		pref[i] = pref[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) {
		int p = pref[i], x = i;
		while (p && x < n) {
			int now = pref[x + p] - pref[x];
			x = min(x+p,n);
			p = now;
			if (!now) break;

		}
		cout << x << endl;
	}
	return 0;
}