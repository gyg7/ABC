#include <bits/stdc++.h>
using namespace std;
int t, n, a[400001];
long long ans;
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;n = 2*n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		priority_queue<int> q;
		ans = a[1];
		for (int i = 1; 2 * i + 1 <= n; i++) {
			q.push(a[2 * i]);
			q.push(a[2 * i + 1]);
			ans += q.top();
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
