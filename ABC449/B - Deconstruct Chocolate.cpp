#include <bits/stdc++.h>
using namespace std;
int h, w, q;
int main() {
	cin >> h >> w >> q;
	for (int i = 1; i <= q; i++) {
		int opt, v;
		cin >> opt >> v;
		if (opt == 1) {
			cout << v*w << endl;
			h -= v;
		} else {
			cout << h*v << endl;
			w -= v;
		}
	}
}