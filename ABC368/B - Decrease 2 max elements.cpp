#include <bits/stdc++.h>
using namespace std;
int n, a[101], vis[101], cnt;
int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt++;
    }
    for (int i = 1;; i++) {
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        if (--a[1] == 0) cnt--;
        if (--a[2] == 0) cnt--;
        if (cnt <= 1) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}