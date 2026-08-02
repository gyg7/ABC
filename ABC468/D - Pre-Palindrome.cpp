#include <bits/stdc++.h>
using namespace std;
char s[10005], t[20010];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int m = 0;
    t[m++] = '#'; 
    for (int i = 0; i < n; i++) {
        t[m++] = s[i];
        t[m++] = '#';
    }
    int ans = 0;
    for (int center = 0; center < m; center++) {
        int l = center, r = center;
        int diff = 0;
        while (l >= 0 && r < m) {
            if (t[l] != '#' && t[r] != '#' && t[l] != t[r]) {
                diff++;
            }
            if (diff > 1) break;
            if (t[l] != '#' || t[r] != '#') {
                ans++;
            }
            
            l--;
            r++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}