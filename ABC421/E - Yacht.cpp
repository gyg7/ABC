#include <bits/stdc++.h>
using namespace std;
#define int long long
const int pw[] = {1, 6, 36, 216, 1296, 7776};
int T = 1;
int a[6];
double f[4][6][7777];
void solve() {
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int n = 0; n < 6; n++) {
		for (int S = 0; S < pw[n]; S++) {
			int tmp = S, cnt[6] = {0};
			for (int j = 0; j < n; j++) {
				cnt[tmp % 6]++;
				tmp /= 6;
			}
			for (int P = 0; P < pw[5 - n]; P++) {
				tmp = P;
				int c[6];
				for (int j = 0; j < 6; j++)
					c[j] = cnt[j];
				for (int j = 0; j < 5 - n; j++) {
					c[tmp % 6]++;
					tmp /= 6;
				}
				int sroce = 0;
				for (int i = 0; i < 6; i++) {
					int tot = 0;
					for (int j = 0; j < 6; j++) if (a[i] == a[j]) tot += c[j];
					sroce = max(sroce, a[i] * tot);
				}
				f[1][n][S] += sroce;
			}
			f[1][n][S] /= pw[5 - n];
		}
	}
	for (int k = 2; k <= 3; k++) {
		for (int n = 0; n < 6; n++) {
			for (int S = 0; S < pw[n]; S++) {
				for (int P = 0; P < pw[5 - n]; P++) {
					double maxv = 0;
					for (int K = 0; K < (1 << (5 - n)); K++) {
						int m = __builtin_popcount(K);
						int tmp = P, T = S;
						for (int i = 0; i < 5 - n; i++) {
							if (K >> i & 1) T = T * 6 + (tmp % 6);
							tmp /= 6;
						}
						maxv = max(maxv, f[k - 1][n + m][T]);
					}
					f[k][n][S] += maxv;
				}
				f[k][n][S] /= pw[5 - n];
			}
		}
	}
	printf("%.10lf\n", f[3][0][0]);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}


