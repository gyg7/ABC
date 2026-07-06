#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> pii;

// 修正：使用 less<pii> 作为比较器
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

		// 修正：使用 find_by_order(i) 而非 find_of_kth(i)
		// 注意：find_by_order 是 0-based 索引
		cout << tr.find_by_order(i)->first << '\n';
	}
}
