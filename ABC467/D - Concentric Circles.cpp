#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll dist2(Point a, Point b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        Point P, Q, R, S;
        cin >> P.x >> P.y;
        cin >> Q.x >> Q.y;
        cin >> R.x >> R.y;
        cin >> S.x >> S.y;
        ll v1x = Q.x - P.x;
        ll v1y = Q.y - P.y;
        ll v2x = S.x - R.x;
        ll v2y = S.y - R.y;

        // 叉积
        ll cross = v1x * v2y - v1y * v2x;

        if (cross != 0) {
            cout << "Yes\n";
        } else {
            Point M1;
            M1.x = P.x + Q.x; 
            M1.y = P.y + Q.y; 

                    ll dR = (2 * R.x - M1.x) * (2 * R.x - M1.x) + (2 * R.y - M1.y) * (2 * R.y - M1.y);
            ll dS = (2 * S.x - M1.x) * (2 * S.x - M1.x) + (2 * S.y - M1.y) * (2 * S.y - M1.y);
            if (dR == dS) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}