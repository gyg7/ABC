#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
typedef atcoder::modint998244353 mint;
typedef long long ll;
ll n, d[100001];
mint fac[21], cnt[100010][22], sumv[10010][22];
int tot;
int getid(ll m) {
	return lower_bound(d + 1, d + 1 + tot, m) - d;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n / i; i++) {
		if (n % i) continue;
		d[++tot] = i;
		if (i != n / i) d[++tot] = n / i;
	}
	sort(d + 1, d + 1 + tot);
	fac[0] = 1;
	for (int i = 1; i <= 20; i++)
		fac[i] = fac[i - 1] * i;
    cnt[1][0]=1;
	for (int i = 1; i <= tot; i++) {
		for (int j = tot; j >= 1; j--) {
			if (d[j] > n / d[i]) continue;
			ll nd = d[j] * d[i];
			if (n % nd) continue;
			int p = getid(nd);
			for (int l = 19; l >= 0; --l) {
				cnt[p][l + 1] += cnt[j][l];
				sumv[p][l + 1] = sumv[p][l + 1] + sumv[j][l] + cnt[j][l] * d[i];
			}
		}
	}
	mint ans = 0;
	for (int i = 1; i <= 20; i++) {
		ans += sumv[tot][i] * fac[i];
	}
	cout << ans.val() << endl;
}