#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "sweet") ++cnt;
        if (s == "salty") cnt = 0;
        if (cnt == 2) {
            if (i == n) break;
            else {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}