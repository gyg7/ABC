#include <bits/stdc++.h>
using namespace std;
int n, q, opt, p, h, cnt[1000001], a[1000001];
int num;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cnt[a[i] = i] = 1;
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> p >> h;
			if (--cnt[a[p]] == 1) num--;
			if (++cnt[a[p] = h] == 2) num++;
		} else cout << num << endl;
	}
}