#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string x, y;
ll len[100];
ll dp[100][26];           
ll pref[3][100005][26];  

ll queryOriginal(int id, ll l, ll r, int c) {
    return pref[id][r][c] - pref[id][l-1][c];
}

ll query(ll l, ll r, int n, int ch) {
    if (n == 1) return queryOriginal(1, l, r, ch);
    if (n == 2) return queryOriginal(2, l, r, ch);
    
    ll Left = len[n - 1];
    if (r <= Left) 
        return query(l, r, n - 1, ch);
    else if (l > Left) 
        return query(l - Left, r - Left, n - 2, ch);
    else {
        ll lcnt = dp[n - 1][ch];
        if (l != 1) 
            lcnt = query(l, Left, n - 1, ch);
        ll rcnt = query(1, r - Left, n - 2, ch);
        return lcnt + rcnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> x >> y;
    int n1 = x.length(), n2 = y.length();
    len[1] = n1;
    len[2] = n2;
    
    for (int i = 3; i <= 92; i++) 
        len[i] = len[i - 1] + len[i - 2];
    for (int c = 0; c < 26; c++) {
        pref[1][0][c] = pref[2][0][c] = 0;
        for (int i = 0; i < n1; i++) 
            pref[1][i+1][c] = pref[1][i][c] + (x[i]-'a' == c);
        for (int i = 0; i < n2; i++) 
            pref[2][i+1][c] = pref[2][i][c] + (y[i]-'a' == c);
    }
    for (int c = 0; c < 26; c++) {
        dp[1][c] = pref[1][n1][c];
        dp[2][c] = pref[2][n2][c];
        for (int i = 3; i <= 92; i++)
            dp[i][c] = dp[i-2][c] + dp[i-1][c];
    }
    
    int q;
    ll l, r;
    char ch;
    cin >> q;
    
    while (q--) {
        cin >> l >> r >> ch;
        int n = 1;
        while (len[n] < r) n++;
        cout << query(l, r, n, ch - 'a') << '\n';
    }
}