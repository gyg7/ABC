#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, x, a[54];
typedef pair<ll, vector<int>> node;
set<node> se;
priority_queue<node> pq;
int main() {
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a  + n, greater<ll>());
	vector<int> aug(n, 0);
	aug[0] = k;
	node t{1ll * a[0] * k, aug};
	pq.push(t);
	se.insert(t);
	for (int i = 1; i <= x; i++) {
		auto [v, aug] = pq.top();
		pq.pop();
		cout << v << endl;
		for (int i = 0; i < n - 1; i++) {
			if (aug[i] == 0) continue;
			ll old = v;
			v = v - a[i] + a[i + 1];
			aug[i]--, aug[i + 1]++;
			node t{v, aug};
			if (se.count(t) == 0) {
				pq.push(t);
				se.insert(t);
			}
			v = old, aug[i]++, aug[i + 1]--;

		}
	}
}