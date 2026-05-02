#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, a[300001], b[300001];
ll ans;
int main() {
	for (cin >> t; t; --t) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans = ans + a[i] + b[i];
		sort(a + 1, a + 1 + n, greater<int>());
		sort(b + 1, b + 1 + n, greater<int>());
		int j = n;
		for (int i = 1; i <= n; i++) {
	while(j&&a[i]+b[j]<m) j--;
    if(!j) break;
ans-=m;
j--;
if(j<=0) break;
		}
		cout << ans << endl;
	}
	return 0;
}
