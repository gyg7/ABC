#include <bits/stdc++.h>
using namespace std;
int n, q, cnt[101], x;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> x;
		if (x >= 1) {
			cnt[x]++;
			cout << x << " ";
		} else {
			int idx = 1;
			for (int i = 2; i <= n; i++)
				if (cnt[idx] > cnt[i]) idx = i;
			cnt[idx]++;
			cout << idx << " ";
		}
	}
	return 0;
}
