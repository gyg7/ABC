#include <bits/stdc++.h>
using namespace std;
int n, x, sum, a[1000001], opt;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> opt;
		if (opt == 1){cin>>x; if (++a[x] == 1) sum++;}
		if (opt == 2){cin>>x; if (--a[x] == 0) sum--;}
		if (opt == 3) cout << sum << endl;
	}
	return 0;
}