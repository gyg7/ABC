#include <bits/stdc++.h>
using namespace std;
deque<pair<int, int>> que;
int q, opt, c, x, k;
int main() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> c >> x;
			que.push_back({c, x});
		}
		if (opt == 2) {
			cin >> k;
			long long sum = 0;
			while (k) {
				long long c = que.front().first, x = que.front().second;
				que.pop_front();
				if (c <= k) {
					sum += c * x;
					k -= c;
				} else {
					sum += k * x;
					que.push_front({c - k, x});
					break;
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}
