#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int MAXW = 10000;  // 根据题目实际范围调整

int n, m;
int u[N], v[N], w[N], a[N];
vector<int> g[N];  // 原图邻接表
int dp[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	// 建原图（无向）
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	
	// 按 w 升序处理顶点
	vector<int> order(n);
	iota(order.begin(), order.end(), 1);  // order = [1,2,...,n]
	sort(order.begin(), order.end(), [&](int x, int y) {
		return w[x] < w[y];
	});
	
	// 对每个顶点（按 w 从小到大）计算 dp
	for (int vtx : order) {
		// 收集所有 w < w[vtx] 的邻居
		vector<pair<int, int>> items;  // (重量=w[nei], 价值=dp[nei])
		for (int nei : g[vtx]) {
			if (w[nei] < w[vtx]) {
				items.push_back({w[nei], dp[nei]});
			}
		}
		
		if (items.empty()) {
			dp[vtx] = 1;
			continue;
		}
		
		// 0-1 背包，容量 = w[vtx] - 1
		int capacity = w[vtx] - 1;
		vector<int> knap(capacity + 1, 0);
		
		for (auto [weight, value] : items) {
			for (int c = capacity; c >= weight; c--) {
				knap[c] = max(knap[c], knap[c - weight] + value);
			}
		}
		
		// 取不超过容量的最大值
		int best = 0;
		for (int c = 0; c <= capacity; c++) {
			best = max(best, knap[c]);
		}
		
		dp[vtx] = 1 + best;
	}
	
	// 计算答案
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1LL * a[i] * dp[i];
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
