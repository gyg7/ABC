#include <bits/stdc++.h>
using namespace std;
int n, a, l = -1, r = -1, ans;
char b;
int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (b == 'L') {
            if (l != -1) ans += abs(l - a);
            l = a;
        }
        if (b == 'R') {
            if (r != -1) ans += abs(r - a);
            r = a;
        }
    }
    printf("%d", ans);
    return 0;
}