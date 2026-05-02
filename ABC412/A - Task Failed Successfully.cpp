#include <bits/stdc++.h>
using namespace std;
int n, a, b, cnt;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (a < b) ++cnt;
		}
	cout << cnt << endl;
	return 0;
}
