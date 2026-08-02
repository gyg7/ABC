#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll Y;
    cin >> N >> M >> Y;
    
    vector<vector<pll>> adj(N + 1); // 0 是虚拟节点, 1~N 是城市
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
        adj[v].push_back({t, u});
    }
    
    vector<ll> X(N + 1);
    for (int i = 1; i <= N; i++) cin >> X[i];
    
    // 翘曲门: 城市 i <-> 虚拟节点 0
    for (int i = 1; i <= N; i++) {
        adj[i].push_back({X[i], 0});        // i -> 0, 代价 X_i
        adj[0].push_back({X[i] + Y, i});     // 0 -> i, 代价 X_i + Y
    }
    
    const ll INF = (1LL << 60);
    vector<ll> dist(N + 1, INF);
    dist[1] = 0;
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int k = 2; k <= N; k++) {
        cout << dist[k] << " ";
    }
    
    return 0;
}