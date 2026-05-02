#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 1;
int T = 1;
int n, k, num;
int D;
struct node {
	int a, b, c;
} p[300001];
queue<int> q1;
priority_queue<int,vector<int>,greater<int>> d;
priority_queue<pair<int, int>> q2;
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		d.push(p[i].a);
	}
	int j = 1;
	while (d.size()) {
		int x = d.top();
		d.pop();
		while (j <= n && p[j].a <= x) {
			q1.push(j);
			j++;
		}
		while (q2.size()) {
			if (-q2.top().first <= x) {
				D -= p[q2.top().second].c;
				q2.pop();
			} else break;
		}
		while (q1.size() && p[q1.front()].c + D <= k) {
			int idx = q1.front();
			q1.pop();
			D += p[idx].c;
			q2.push({-(x + p[idx].b), idx});
			int key = x + p[idx].b;
			d.push(key);
			++num;
			cout << x << endl;
		}
	}
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

