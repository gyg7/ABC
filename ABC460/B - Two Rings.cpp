#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll dx = x1 - x2;
        ll dy = y1 - y2;
        ll d2 = dx * dx + dy * dy;

        ll sum_r = r1 + r2;
        ll sum_r2 = sum_r * sum_r;
        ll diff_r = abs(r1 - r2);
        ll diff_r2 = diff_r * diff_r;

        if (d2 >= diff_r2 && d2 <= sum_r2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}