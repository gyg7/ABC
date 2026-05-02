#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200001;
int n, m, u, v;
vector<int> ve[N];
int d[N][2], from[N][2];
string s;
queue<pair<int, int>> que;
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {
	memset(d, -1, sizeof d);
}
void readmeta() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	cin >> s;
}
void solve() {

	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'S') {
			que.push({i, 0});
			d[i][0] = 0;
			from[i][0] = i;
		}
	}
	while (que.size()) {
		int u = que.front().first, o = que.front().second;
		que.pop();
		for (int v : ve[u]) {
			if (d[v][0] == -1) {
				d[v][0] = d[u][o] + 1;
				from[v][0] = from[u][o];
				que.push({v, 0});
			} else if (d[v][1] == -1 && from[v][0] != from[u][o]) {
				d[v][1] = d[u][o] + 1;
				from[v][1] = from[u][o];
				que.push({v, 1});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (s[i - 1] == 'D') cout << d[i][0] + d[i][1] << endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}
