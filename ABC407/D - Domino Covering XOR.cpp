#include <bits/stdc++.h>
using namespace std;
#define rep(i,b) for(int i=0;i<b;i++)
typedef unsigned ui;
int w, h;
bitset < 1 << 20 > vis;
long long a[20][20];
long long  ans;

queue<ui> que;
int main() {
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> a[i][j];
	ui cover_w = 3u, cover_v = (1u << w) + 1;
	que.push(0);
	vis[0] = 1;
	while (que.size()) {
		ui u = que.front();
		que.pop();
		rep(i, h) rep(j, w - 1) { if(u&(cover_w<<(i*w+j))) continue;
			int to = u | (cover_w << (i * w + j));
			if (vis[to] == 0) {
				vis[to] = 1;
				que.push(to);
			}
		}
		rep(i, h - 1) rep(j, w) { if(u&(cover_v<<(i*w+j))) continue;
			int to = u | (cover_v << (i * w + j));
			if (vis[to] == 0) {
				vis[to] = 1;
				que.push(to);
			}
		}
	}
	rep(s, (1 << (w * h))) {
		if (!vis[s]) continue;
		long long tmp = 0;
		rep(i, h) rep(j, w) {
			if ((s >> (i * w + j))&1) continue;
			tmp ^= a[i][j];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
