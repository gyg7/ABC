#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

void solve() {
	string s;
	cin >> s;
	mint ans = 0;
	long long last = -1;
	
	for (int i = 0; i < (int)s.size(); i++) {
		if (i == s.size() - 1 || s[i] != s[i+1]) {
			long long len = i - last;
			ans += len * (len + 1) / 2;
			last = i;
		}
	}
	cout << ans.val() << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
