#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string ans[] = {"No", "Yes"};
map<int, int> cnt;
int a[1001], b[1001], c, x, n, m, l, q;
int main() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> m;
	rep(i, 1, m) cin >> b[i];
	cin >> l;
	rep(i, 1, l) {
		cin >> c;
		rep(j, 1, n) rep(k, 1, m) cnt[c + a[j] + b[k]] = 1;
	}
	cin >> q;
	rep(i, 1, q) {
		cin >> x;
		cout << ans[cnt.count(x)] << endl;
	}
}