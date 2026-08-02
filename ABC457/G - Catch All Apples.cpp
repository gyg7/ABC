#include <bits/stdc++.h>
using namespace std;

struct FenwickMax {
    int n;
    vector<int> f;
    FenwickMax(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        f.assign(n + 1, 0);
    }
    void update(int i, int val) {
        for (; i <= n; i += i & -i) f[i] = max(f[i], val);
    }
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) res = max(res, f[i]);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    
    vector<pair<int,int>> ab;
    vector<int> all_b;
    for (auto &[y, x] : p) {
        ab.push_back({x + y, y - x});
        all_b.push_back(y - x);
    }
    
    sort(ab.begin(), ab.end());
    
    sort(all_b.begin(), all_b.end());
    all_b.erase(unique(all_b.begin(), all_b.end()), all_b.end());
    
    int m = all_b.size();
    auto getId = [&](int b) {
        int pos = lower_bound(all_b.begin(), all_b.end(), b) - all_b.begin();
        return m - pos;
    };
    
    FenwickMax fw(m);
    int ans = 0;
    
    for (auto &[a, b] : ab) {
        int id = getId(b);
        int res = (id > 1) ? fw.query(id - 1) : 0;
        int len = res + 1;
        ans = max(ans, len);
        fw.update(id, len);
    }
    
    cout << ans << endl;
    return 0;
}