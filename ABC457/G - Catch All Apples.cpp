#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
const int N = 2e5+10;
int n;
atcoder::fenwick_tree<int> bit;
struct node {
	int y, i;
};
vector<node> ve[2 * N];
int dp[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		ve[x - y + n].push_back(node{x + y, i});
	}
	for (int i = 2 * n; i >= 0; i--) {
		sort(ve[i].begin(), ve[i].end(), [](node a, node b) {
			return a.y > b.y;
		});
		for (auto u : ve[i]) {
			dp[u.id]=
		}
	}
}
