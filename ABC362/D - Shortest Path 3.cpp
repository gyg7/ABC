#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
typedef long long ll;
const ll inf = LLONG_MAX;
int n, m, u, v;
ll w, a[maxn], b[maxn];
vector<pair<int, ll>> ve[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
int vis[maxn];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &u, &v, &w);
		ve[u].push_back({v, w});
		ve[v].push_back({u, w});
	}
	for (int i = 2; i <= n; i++)
		b[i] = inf;
	b[1] = a[1];
	que.push({0, 1});
	while (que.size()) {
		auto [_, u] = que.top();
		que.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v, w] : ve[u])
			if (b[u] + a[v] + w < b[v]) {
				b[v] = b[u] + a[v] + w;
				que.push({b[v], v});
			}
	}
	for (int i = 2; i <= n; i++)
		printf("%lld ", b[i]);
	return 0;
}
