#include <bits/stdc++.h>
using namespace std;
int n, r, d[101], a[101], dp[101][2];
queue<int> q;
int mx;
int main() {
	cin >> n >> r;
	q.push(r);
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> a[i];
		for (int S = q.size(); S >= 1; S--) {
			int u = q.front();
			q.pop();
			//		mx = max(mx, u);
			if (d[i] == 1)
				if (1600 <= u && u <= 2799)
					q.push(u + a[i]);
				else q.push(u);
			if (d[i] == 2)
				if (1200 <= u && u <= 2399)
					q.push(u + a[i]);
				else q.push(u);
		}
	}
	for (int i = q.size(); i; i--) {
		int u = q.front();
		q.pop();
		mx = max(mx, u);
	}
	printf("%d", mx);
	return 0;
}