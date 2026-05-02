#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int, vector<int>, greater<int>> que;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int x;
			cin >> x;
			que.push(x);
		} else {
			cout << que.top() << endl;
			que.pop();
		}
	}
	return 0;
}

