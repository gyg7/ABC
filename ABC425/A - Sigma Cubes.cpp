#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, sum;
void solve() {
	cin >> n;
	for (int i = 1, j = -1; i <= n; i++, j = -j) 
		sum += i * i * i * j;
	cout<<sum<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int t = 1;
//	cin >> t;
	while (t--) solve();
}


