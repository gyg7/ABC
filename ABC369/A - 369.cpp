#include <bits/stdc++.h>
using namespace std;
int a, b, cnt;
int main(void) {
    cin >> a >> b;
    for (int x = -300; x <= 200; x++) {
        if (x <= a && a <= b&&a - x == b - a) cnt++;
        else if (a <= x && x <=b&&x - a == b - x) cnt++;
        else if (a <= b && b <= x&&b - a == x - b) cnt++;
        else  if (x <= b && b <= a&&b - x == a - b) cnt++;
        else if (b <= x && x <=a&&x - b == a - x) cnt++;
        else if (b <= a && a <= x&&a - b == x - a) cnt++;
    }
    cout << cnt << endl;
    return 0;
}