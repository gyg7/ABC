#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
	int l, d, k, c, to, nxt;
} e[N];
int head[N], tot;
int n, m;
int dp[N];

void add(int u, int v, int l, int d, int k, int c) {
	e[++tot] = {l, d, k, c, v, head[u]};
	head[u] = tot;
}

// 二分查找最大可行班次
int find_max_departure(int l, int d, int k, int c, int limit) {
	int be = 0, rg = k - 1, ans = -1;
	while (be <= rg) {
		int mid = (be + rg) / 2;
		if (l + mid * d + c <= limit) {
			ans = mid;
			be = mid + 1;
		} else {
			rg = mid - 1;
		}
	}
	if (ans == -1) return -1;
	return l + ans * d;
}

void solve() {
	cin >> n >> m;
	memset(head, 0, sizeof head);
	tot = 0;
	
	for (int i = 1; i <= m; ++i) {
		int l, d, k, c, u, v;
		cin >> l >> d >> k >> c >> u >> v;
		add(v, u, l, d, k, c);  // 反向建图
	}
	
	memset(dp, -1, sizeof dp);
	dp[n] = inf;
	
	// 优先队列：存储 (到达时间, 节点)
	// 用最大堆，因为要优先处理到达时间最晚的节点
	priority_queue<pair<int, int>> pq;
	pq.push({inf, n});
	
	while (!pq.empty()) {
		auto [time, u] = pq.top();
		pq.pop();
		
		if (time < dp[u]) continue;
		
		for (int i = head[u]; i; i = e[i].nxt) {
			auto [l, d, k, c, v, _] = e[i];
			
			int start_time = find_max_departure(l, d, k, c, time);
			if (start_time == -1) continue;
			
			if (start_time > dp[v]) {
				dp[v] = start_time;
				pq.push({dp[v], v});
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		if (dp[i] == -1) cout << "Unreachable\n";
		else cout << dp[i] << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while (t--) solve();
	return 0;
}
