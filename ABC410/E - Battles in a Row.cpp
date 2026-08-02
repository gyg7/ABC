#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, H, M;
int a[3005], b[3005];
int dp[3005];  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> H >> M;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    
    
    fill(dp, dp + H + 1, INF);
    dp[0] = 0;  
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = H; j >= 0; j--) {
            int newDp = INF;
            
            if (j >= a[i] && dp[j - a[i]] < INF) {
                newDp = min(newDp, dp[j - a[i]]);  
            }
            
            if (dp[j] < INF) {
                newDp = min(newDp, dp[j] + b[i]);  
            }
            dp[j] = newDp;
        }
        
        
        bool ok = false;
        for (int j = 0; j <= H; j++) {
            if (dp[j] <= M) {  
                ok = true;
                break;
            }
        }
        if (ok) ans = i;
        else break;  
    }
    
    cout << ans << endl;
    return 0;
}