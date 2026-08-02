#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    const int S = 1024;
    vector<vector<bool>> vis(n+1, vector<bool>(S));
    queue<pair<int,int>> q;
    
    q.push({1, 0});
    vis[1][0] = true;
    
    while (!q.empty()) {
        auto [u, s] = q.front(); q.pop();
        for (auto &[v, w] : adj[u]) {
            int ns = s ^ w;
            if (!vis[v][ns]) {
                vis[v][ns] = true;
                q.push({v, ns});
            }
        }
    }
    
    for (int s = 0; s < S; s++) {
        if (vis[n][s]) {
            cout << s << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}