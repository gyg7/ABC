#include <bits/stdc++.h>
using namespace std;
#define int long long
int t = 1;
void solve() {
	int x, y;
cin>>x>>y;
cout<<(x+y-1)%12+1<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin>>t;
	while (t--) solve();
	return 0;
}


