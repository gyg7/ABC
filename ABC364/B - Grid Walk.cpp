#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
string s;
char mp[51][51];
int main(void) {
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    cin >> s;
    for (char ch : s) {
        if (ch == 'U' && mp[x - 1][y] == '.') x--;
        if (ch == 'D' && mp[x + 1][y] == '.') x++;
        if (ch == 'L' && mp[x][y - 1] == '.') y--;
        if (ch == 'R' && mp[x][y + 1] == '.') y++;
    }
    printf("%d %d", x, y);
    return 0;
}