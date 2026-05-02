#include <bits/stdc++.h>
using namespace std;
int n, c, t[101], id, cnt;
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	id = 1, cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (t[i] - t[id] >= c) {
			id = i;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}