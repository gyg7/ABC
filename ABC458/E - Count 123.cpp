#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
typedef atcoder::modint998244353 mint;
const int N = 3000300;
mint jc[N], jv[N];
mint C(int a, int b) {
	if (a < b) return 0;
	return jc[a] * jv[b] * jv[a - b];
}
int main() {
	jc[0] = 1;
	for (int i = 1; i < N; i++) {
		jc[i] = jc[i - 1] * i;
	}
	jv[N - 1] = jc[N - 1].pow(998244353 - 2);
	for (int i = N - 2; i >= 0; i--) {
		jv[i] = jv[i + 1] * (i + 1);
	}
	int x, y, z;
	cin >> x >> y >> z;
	mint ans = 0;
	for (int i = 0; i <= y + 1; i++) {
		ans += C(y + 1, i) * C(x - 1, i - 1) * C(y + z - i, z);
	}
	cout << ans.val() << endl;
	return 0;
}