#include <bits/stdc++.h>
using namespace std;
int n, m, x, a, b;
vector<int> ve[200001], rve[200001];
priority_queue<pair<long long, pair<int, int>>> q;
long long dist[200001][2], vis[200001][2];
int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		ve[a].push_back(b);
		rve[b].push_back(a);
	}
	memset(dist, 0x3f, sizeof dist);
	q.push({0, {1, 0}});
	dist[1][0] = 0;
	while (!q.empty()) {
		int u = q.top().second.first;
		int w = q.top().second.second;
		q.pop();
		if (vis[u][w]) continue;
		vis[u][w] = 1;
		for (int v : ve[u]) {
			int val = w == 0 ? 1 : x + 1;
			if (dist[v][0] > dist[u][w] + val) {
				dist[v][0] = dist[u][w] + val;
				q.push({-dist[v][0], {v, 0}});
			}
		}
		for (int v : rve[u]) {
			int val = w == 1 ? 1 : x + 1;
			if (dist[v][1] > dist[u][w] + val) {
				dist[v][1] = dist[u][w] + val;
				q.push({-dist[v][1], {v, 1}});
			}
		}
	}
	cout << min(dist[n][0], dist[n][1]) << endl;
	return 0;
}