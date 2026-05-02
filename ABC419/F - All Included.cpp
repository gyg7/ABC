#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, l;
string s[9];
struct tree {
	int idx;
	int ch[27];
	int fail;
} tr[81];
int tot;
void insert(int idx) {
	int now = 0;
	for (char ch : s[idx]) {
		if (tr[now].ch[ch - 'a'] == 0)
			tr[now].ch[ch - 'a'] = ++tot;
		now = tr[now].ch[ch - 'a'];
	}
	tr[now].idx |= (1 << (idx - 1));
}
void build() {
	queue<int> que;
	for (int i = 0; i < 26; i++)
		if (tr[0].ch[i])
			que.push(tr[0].ch[i]);
	while (que.size()) {
		int u = que.front();
		que.pop();
		tr[u].idx |= tr[tr[u].fail].idx;
		for (int i = 0; i < 26; i++) {
			if (tr[u].ch[i]) {
				tr[tr[u].ch[i]].fail = tr[tr[u].fail].ch[i];
				que.push(tr[u].ch[i]);
			} else tr[u].ch[i] = tr[tr[u].fail].ch[i];
		}
	}
}
int f[2][81][1 << 8], now;
void add(int &x, int y) {
	x = (x + y) % mod;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		insert(i);
	}
	build();
	f[0][0][0] = 1;
	for (int i = 1; i <= l; i++) {
		memset(f[1 - now], 0, sizeof f[1 - now]);
		for (int j = 0; j <= tot; j++)
			for (int S = 0; S < (1 << n); S++) {
				int gx = f[now][j][S];
				if (!gx) continue;
				for (int ch = 0; ch < 26; ch++) {
					int to = tr[j].ch[ch];
					add(f[1 - now][to][S | tr[to].idx], gx);
				}
			}
		now = 1 - now;
	}
	int ans = 0;
	for (int i = 0; i <= tot; i++)
		add(ans, f[now][i][(1 << n) - 1]);
	cout << ans << endl;
	return 0;
}

