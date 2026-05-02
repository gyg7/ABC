#include <bits/stdc++.h>
using namespace std;
int st[201], top, q, opt, x;
int main() {
	cin >> q;
	top = 100;
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 2)
			cout << st[top--] << endl;
		else {
			cin >> x;
			st[++top] = x;
		}
	}
	return 0;
}