#include <bits/stdc++.h>
using namespace std;
const int  N = 3e5 + 10;
int q, opt[N], a[N];
multiset<int> se;
int main() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> opt[i] >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		if (opt[i] == 1) se.insert(a[i]);
		else se.erase(se.begin(), se.lower_bound(a[i]+1));
		cout << se.size() << endl;
	}
}