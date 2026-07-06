#include <bits/stdc++.h>
using namespace std;
int n, k, m;
priority_queue<int> pq[200001];
priority_queue<pair<int, int>> Pq;
int mx[200001];
vector<int> ve;
int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		int c, v;
		cin >> c >> v;
		pq[c].push(v);
		mx[c] = max(mx[c], v);
	}
	for (int i = 1; i <= n; i++) {
		Pq.push({mx[i], i});
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int v = Pq.top().first;
		int c = Pq.top().second;
		pq[c].pop();
		Pq.pop();
		mx[c] = pq[c].top();
		ans += v;
		ve.push_back(c);
	}
	for (int v : ve) {
		Pq.push({mx[v], v});
	}
	for (int i = m + 1; i <= k; i++) {
		int v = Pq.top().first;
		int c = Pq.top().second;
		Pq.pop();
		pq[c].pop();
		Pq.push({pq[c].top(), c});
		ans += v;
	}
	cout << ans << endl;
}
