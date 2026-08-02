#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;

int n, a[500010];
mint H[500010], PH[500010]; // 调和数及其前缀和

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        H[i] = H[i-1] + mint(1) / i;
    }
    
    for (int i = 1; i <= n; i++) {
        PH[i] = PH[i-1] + H[i];
    }
    
    mint ans = 0;
    for (int k = 1; k <= n; k++) {
        ans += mint(a[k]) * (PH[n] - PH[n-k] - PH[k-1]);
    }
    
    cout << ans.val() << endl;
    return 0;
}