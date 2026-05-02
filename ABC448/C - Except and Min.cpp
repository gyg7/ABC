#include <bits/stdc++.h>
using namespace std;
int n, q, a[300001], k, b[6], d[6], tot;
priority_queue<int, vector<int>, greater<int>> pq, pq1;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pq.push(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> b[j];
			pq1.push(a[b[j]]);
		}
		tot = 0;
		while (pq1.size() && pq.top() == pq1.top()) {
			d[++tot] = pq.top();
			pq.pop();
			pq1.pop();
		}
		while (pq1.size()) pq1.pop();
		cout << pq.top() << endl;
		for (int i = 1; i <= tot; i++)
			pq.push(d[i]);
	}
}