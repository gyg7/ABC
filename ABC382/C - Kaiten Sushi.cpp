#include <bits/stdc++.h>
using namespace std;
int n, m, p1[200001], p2[200001];
vector<int> ve[200001];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int ans[200001];
priority_queue<pair<int, int>> q;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		p1[i] = read();//plople
	for (int i = 1; i <= m; i++) {
		p2[i] = read();
		q.push({p2[i], i});
	}
	for (int i = 1; i <= n; i++) {
		while (q.size() && q.top().first >= p1[i]) {
			ans[q.top().second] = i;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		if (ans[i] == 0) ans[i] = -1;
		cout << ans[i] << endl;
	}
}