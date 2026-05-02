#include <bits/stdc++.h>
using namespace std;
int n, a[500010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = min(n, i + a[i] - 1);
	}
	int r = a[1], pos = 1;
	for (int i = 1; i <= n; i++) {
		int p = r;
		for (int j = pos; j <= r; j++) {
			if (p < a[j]) {
				p = a[j];
				pos = j;
			}
		}
		if (r == p) {
			cout<<r<<endl;
			return 0;
		}
		r = p;
	}
}