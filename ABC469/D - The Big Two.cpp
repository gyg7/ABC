#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> ve[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ve[x].push_back(i);
        ve[y].push_back(i);
    }
    
    // 预处理排序
    for (int i = 1; i <= n; i++) {
        sort(ve[i].begin(), ve[i].end());
    }
    
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 1);
    sort(vertices.begin(), vertices.end(), [&](int a, int b) {
        return ve[a].size() > ve[b].size();
    });
    
    int ans = 0;
    
    // 优化1：提前处理度数为m的顶点
    vector<int> full_degree;
    for (int i = 1; i <= n; i++) {
        if (ve[i].size() == m) {
            full_degree.push_back(i);
        }
    }
    int fd = full_degree.size();
    ans += fd * (n - fd) + fd * (fd - 1) / 2;
    
    // 只考虑非全度顶点
    vector<int> normal;
    for (int v : vertices) {
        if (ve[v].size() < m) {
            normal.push_back(v);
        }
    }
    
    // 优化2：使用哈希集合存储边，加速查询
    // 对每个顶点，建立边的哈希集合
    vector<unordered_set<int>> edge_set(n + 1);
    for (int i = 1; i <= n; i++) {
        edge_set[i] = unordered_set<int>(ve[i].begin(), ve[i].end());
    }
    
    // 优化3：只检查度数之和 >= m 的配对
    for (int i = 0; i < normal.size(); i++) {
        int u = normal[i];
        for (int j = i + 1; j < normal.size(); j++) {
            int v = normal[j];
            if (ve[u].size() + ve[v].size() < m) break;
            
            // 优化4：用较小的集合遍历
            int cnt = 0;
            const vector<int>& smaller = (ve[u].size() <= ve[v].size()) ? ve[u] : ve[v];
            const vector<int>& larger = (ve[u].size() <= ve[v].size()) ? ve[v] : ve[u];
            
            // 计算交集大小
            for (int id : smaller) {
                if (binary_search(larger.begin(), larger.end(), id)) {
                    cnt++;
                }
            }
            
            if (ve[u].size() + ve[v].size() - cnt == m) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}