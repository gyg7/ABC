#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();

		vector<int> cnt(26);
		for (char ch : s) cnt[ch - 'a']++;

		int mx = *max_element(cnt.begin(), cnt.end());
		if (2 * mx > n + 1) {
			cout << "No\n";
			continue;
		}

		cout << "Yes\n";

		// 最大堆: (次数, 字符)
		priority_queue<pair<int, char>> pq;
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) pq.push({cnt[i], 'a' + i});
		}

		string res;
		pair<int, char> prev = {0, '#'};  // 上一次取出的（次数-1后的）

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			res += cur.second;
			cur.first--;

			// 把prev放回（如果还有剩余）
			if (prev.first > 0) pq.push(prev);

			prev = cur;  // 当前字符冷却一轮
		}

		cout << res << "\n";
	}
	return 0;
}