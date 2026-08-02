#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> pii;

tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;

int x, n, a, b, cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> x >> n;
	tr.insert({x, ++cnt});

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		tr.insert({a, ++cnt});
		tr.insert({b, ++cnt});
		cout << tr.find_by_order(i)->first << '\n';
	}
}