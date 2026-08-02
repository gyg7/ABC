#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200001;
int T = 1;
int n;
struct skill {
	int a, b;
} sk;
int ans;
vector<int> ve[N];
queue<int> que;
bool vis[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sk.a >> sk.b;
		ve[sk.a].push_back(i);
		ve[sk.b].push_back(i);
	}
	que.push(0);
	while (que.size()) {
		int u = que.front();
		que.pop();
		for (int v : ve[u]) {
			if (vis[v] == 0) {
				vis[v] = 1;
				que.push(v);
				++ans;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}