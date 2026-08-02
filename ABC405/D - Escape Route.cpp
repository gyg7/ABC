#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};  // 上、左、下、右
const int dy[4] = {0, -1, 0, 1};
const char ch[4] = {'v', '>', '^', '<'};  // 对应的方向字符
int h, w;
char s[1002][1002];
bool vis[1002][1002];
queue<pair<int, int>> que;

int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
            vis[i][j] = false;  
            if (s[i][j] == 'E') {
                que.push({i, j});
                vis[i][j] = true; 
            }
        }
    }

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 1 && tx <= h && ty >= 1 && ty <= w && s[tx][ty] == '.' && !vis[tx][ty]) {
                s[tx][ty] = ch[i];  
                vis[tx][ty] = true; 
                que.push({tx, ty}); 
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            putchar(s[i][j]);
        }
        putchar('\n');
    }

    return 0;
}