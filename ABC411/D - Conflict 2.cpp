#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    crope s[200005];
    
    while (q--) {
        int op, p;
        cin >> op >> p;
        if (op == 1) {
            s[p] = s[0];
        } else if (op == 2) {
            string t; cin >> t;
            s[p].append(t.c_str());
        } else {
            s[0] = s[p];
        }
    }
    
    for (char c : s[0]) cout << c;
    cout << '\n';
    
    return 0;
}