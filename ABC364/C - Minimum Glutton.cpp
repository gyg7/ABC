#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
} p[200010];
long long n, x, y, sx, sy, ans1, ans2;
bool cmpx(node a, node b) {
    if (a.x > b.x && a.y > b.y) return 1;
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
}
bool cmpy(node a, node b) {
    if (a.x > b.x && a.y > b.y) return 1;
    if (a.y != b.y) return a.y > b.y;
    if (a.x != b.x) return a.x > b.x;
}
int main(void) {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x;
    for (int i = 1; i <= n; i++)
        cin >> p[i].y;
    sort(p + 1, p + 1 + n, cmpx);
    sx = sy = 0;
    for (int i = 1; i <= n; i++) {
        sx += p[i].x;
        sy += p[i].y;
        if (sx > x || sy > y) {
            ans1 = i;
            break;
        }
    }
    if (ans1 == 0) ans1 = n;
    sort(p + 1, p + 1 + n, cmpy);
    sx = sy = 0;
    for (int i = 1; i <= n; i++) {
        sx += p[i].x;
        sy += p[i].y;
        if (sx > x || sy > y) {
            ans2 = i;
            break;
        }
    }
    if (ans2 == 0) ans2 = n;
    printf("%d", min(ans1, ans2));
    return 0;
}