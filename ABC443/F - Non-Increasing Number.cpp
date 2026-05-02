#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
pii a[3000001][11];
int dp[3000001][11];
queue<pii> que;
int main() {
	cin >> n;
	if (n <= 9) {
		cout << n << endl;
        return 0;
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= 9; i++) {
		dp[i][i] = 1;
		a[i][i] = {-1, -1};
		que.push({i, i});
	}
	pii cur = {-1, -1};
	while (que.size()) {
		auto [x, u] = que.front();
		que.pop();
		if (!x) {
			cur = {x, u};
			break;
		}
		for (int i = u; i <= 9; i++) {
			int v = (x * 10 + i) % n;
			if (dp[v][i] != 0x3f3f3f3f) continue;
			dp[v][i] = dp[x][u] + 1;
			a[v][i] = {x, u};
			que.push({v, i});
		}
	}
    if(cur.first==-1){
        cout<<-1<<endl;
        return 0;
    }
	string ans = "";
	while (cur.first != -1) {
		ans.push_back(cur.second + '0');
		cur = a[cur.first][cur.second];
	}
	reverse(ans.begin(), ans.end());
	for (auto ch : ans) putchar(ch);
}