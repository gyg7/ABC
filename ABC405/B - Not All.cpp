#include <bits/stdc++.h>
using namespace std;
int n, m, x[101], cnt[101], num;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (++cnt[x[i]] == 1) num++;
	}

	for (int i = n; i >= 0; i--) {
		if (num != m) {
			cout << n - i << endl;
			break;
		}
		if (--cnt[x[i]] == 0) num--;
	}
	return 0;
}
