#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
int n, a[200010];
vector<int> ve[1000010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= a[i] / j; j++) {
			if (a[i] % j) continue;
			ve[j].push_back(i);
			if (j * j != a[i])
				ve[a[i] / j].push_back(i);
		}
	}
	dsu D(n + 1);
	long long ans = 0;
	for (int i = 1000000; i >= 1; i--) {
		int s = ve[i].size();
		if (s == 0) continue;
		int u = ve[i][0];
		for (int j = 1; j < s; j++) {
			int v = ve[i][j];
            if(!D.same(u,v)){
			D.merge(u, v);
			ans += i;}
		}
	}
	cout << ans << endl;
	return 0;
}