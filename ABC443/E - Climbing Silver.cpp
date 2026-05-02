#include <bits/stdc++.h>
using namespace std;
int t, n, c, top[5010];
char s[5010][5010];
bool vis[5010][5010];
int main() {
	cin >> t;
	for (int _ = 0; _ < t; _++) {
		cin >> n >> c;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> s[i][j];
				vis[i][j] = false;
				top[j] = 0;
			}
		for (int j = 1; j <= n; j++) {
			for (int i = n; i >= 1; i--) {
				top[j] = i;
				if (s[i][j] == '#')  break;
			}
		}
		vis[n][c] = true;
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= n; j++) {
				if (!vis[i][j]) continue;
				if (1 <= j - 1 && (s[i - 1][j - 1] == '.' || i - 1 == top[j - 1])) vis[i - 1][j - 1] = true;
				if (j + 1 <= n && (s[i - 1][j + 1] == '.' || i - 1 == top[j + 1])) vis[i - 1][j + 1] = true;
                if(s[i-1][j]=='.'||i-1==top[j]) vis[i-1][j]=true;
				if (i == top[j]) for (int x = 1; x < i; x++) vis[x][j] = true;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%1d", vis[1][i]);
		puts("");
	}
}