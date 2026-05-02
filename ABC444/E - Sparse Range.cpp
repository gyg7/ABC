#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[400010];
set<int> S;
int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int r = 1;
	long long ans = 0;
	for (int l = 1; l <= n; l++) {
		while (r <= n) {
			if (S.count(a[r])) break;
			auto it = S.insert(a[r]).first;
			if (it != S.begin() && a[r] - *prev(it) < d) {
				S.erase(it);
				break;
			}
			if (next(it) != S.end() && *next(it) - a[r] < d) {
				S.erase(it);
				break;
			}
			r++;
		}
		ans += r - l;
		S.erase(a[l]);
	}
	cout << ans << endl;
}