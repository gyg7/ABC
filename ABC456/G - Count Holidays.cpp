#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
typedef atcoder::modint998244353 mint;
const int N = 2e5+10;
mint pw2[N], fac[N];
mint C(int n, int m) {
	return fac[n] / (fac[m] * fac[n - m]);
}
mint ans[N], suf_mul[N];
char s[N];
int n;
void update(int n) {
	for (int k = 0; k < n; k++) {
		mint sm = 0;
		for (int i = 0; n - (k + 2) * i >= 0; i++) {
			int m = n - (k + 2) * i;
			mint tmp = 1ll * pw2[m] * C(m + i, m);
			if (m - k - 1 >= 0) tmp += -1ll * pw2[m - k - 1] * C(m - k - 1 + i, m - k - 1);
			if (i & 1) tmp = -tmp;
			sm += tmp;
		}
		ans[k] = ans[k] * sm;
	}
	suf_mul[n] *= pw2[n];

}
int main() {
	pw2[0] = 1;
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		pw2[i] = pw2[i - 1] * 2;
		fac[i] = i * fac[i - 1];
	}
	for (int i = 0; i < N; i++) {
		ans[i] = 1;
		suf_mul[i] = 1;
	}
	scanf("%d", &n);
	scanf("%s", s + 1);
	s[n + 1] = 'x';
	int len = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (s[i] == 'x') {
			if (len) update(len);
			len = 0;
		} else ++len;
	}
	for (int i = 1; i <= n; i++) {
		suf_mul[i] *= suf_mul[i - 1];
		ans[i] *= suf_mul[i];
	}
	for (int i = 1; i <= n; i++)
		cout << (ans[i] - ans[i - 1]).val() << endl;

}