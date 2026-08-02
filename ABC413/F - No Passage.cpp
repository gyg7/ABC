#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, k;
int a[3001][3010], cnt[3010][3010];
int main() {
	cin >> n >> m >> k;
	memset(a, -1, sizeof a);
	queue<pair<int, int>> q;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 0;
		q.push({x, y});
	}
	for (int i = 0; q.size(); i++) {
		for (int s = q.size(); s; --s) {
			auto [x, y] = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k], ty = y + dy[k];
				if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if (a[tx][ty] == -1) {
					if (++cnt[tx][ty] == 2) {
						a[tx][ty] = i + 1;
						q.push({tx, ty});
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for(int j = 1;j<=m;j++){
            if(a[i][j]==-1) continue;
            ans+=a[i][j];}
	}
    cout<<ans<<endl;
	return 0;
}