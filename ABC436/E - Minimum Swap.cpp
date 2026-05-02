#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
int n, p[N], vis[N];

int main() {
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int j = 0, ii = i;
		while (!vis[ii]) {
			vis[ii] = 1;
			j++;
            ii=p[ii];
		}
        if(j>1)
		ans += 1ll*j * (j - 1) / 2;
	}
	cout << ans << endl;
}