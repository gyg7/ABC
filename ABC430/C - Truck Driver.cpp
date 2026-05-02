#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a, b;
char s[300010];
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	scanf("%lld%lld%lld",&n,&a,&b);
    scanf("%s",s+1);

}
void solve() {
	int ans = 0, r1 = 0, r2 = 0, n1 = 0, n2 = 0;
	for (int i = 1; i <= n; i++) {
		while (r1+1 <= n && n1 < a) n1 += (s[++r1] == 'a');
		while (r2+1 <= n && n2 < b) n2 += (s[++r2] == 'b');
		if (n1 < a) break;
		if (r1 <= r2){
            if(n2==b) ans += r2 - r1;
            else ans+=n-r1+1;
        }
        n1-=(s[i]=='a');
        n2-=(s[i]=='b');
	}
	cout << ans << endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}