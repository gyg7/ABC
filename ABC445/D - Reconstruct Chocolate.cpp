#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int H, W, n, h[N], w[N], id1[N], id2[N];
int x[N], y[N];
bool vis[N];
int main() {
	cin >> H >> W >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];
		id1[i] = id2[i] = i;
	}
	sort(id1 + 1, id1 + 1 + n, [](int x, int y) {
		return h[x] > h[y];
	});
	sort(id2 + 1, id2 + 1 + n, [](int x, int y) {
		return w[x] > w[y];
	});
	for (int i = 1, p = 1, q = 1; i <= n; i++) {
		while (vis[id1[p]]) ++p;
		while (vis[id2[q]]) ++q;
		if (h[id1[p]] == H) {
			int id = id1[p];
			vis[id] = true;
			x[id] = 1;
			y[id] = W - w[id] + 1;
			W -= w[id];
		} else if (w[id2[q]] == W) {
			int id = id2[q];
			vis[id] = true;
			y[id] = 1;
			x[id] = H - h[id] + 1;
			H -= h[id];
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", x[i], y[i]);
}