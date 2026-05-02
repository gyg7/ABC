#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, vis[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l;
		int ans = 0;
		for (int j = 1; j <=l; j++) {
			cin >> x;
			if (vis[x] == 0 && ans == 0)
				vis[ans=x] = 1;
		}
		cout << ans << endl;
	}
}