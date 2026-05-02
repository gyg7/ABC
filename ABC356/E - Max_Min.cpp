#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1000;
#define int long long
struct node {
	int sum, ls, rs;
} tree[2 * maxn];
int cnt = 1, mx;
#define son int p=1,int pl=1,int pr=maxn-1
#define lson tree[p].ls,pl,mid
#define rson tree[p].rs,mid+1,pr
void mofiy(int x, son) {
	if (pl == pr) {
		tree[p].sum++;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) {
		if (tree[p].ls == 0) tree[p].ls = ++cnt;
		mofiy(x, lson);
	} else {
		if (tree[p].rs == 0) tree[p].rs = ++cnt;
		mofiy(x, rson);
	}
	tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
}
int query(int l, int r, son) {
	if(l>r) return 0;
	if (l <= pl && pr <= r)
		return tree[p].sum;
	int mid = ((pl + pr) / 2);
	if (r <= mid) return query(l, r, lson);
	if (mid < l) return query(l, r, rson);
	return query(l, r, lson) + query(l, r, rson);
}
int n, num[200001];
long long sum;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + n + 1);
	mx = num[n];
	for (int i = 1; i <= n; i++)
		mofiy(num[i]);
	n = unique(num, num + n + 1) - (num + 1);
	for (int i = 1; i <= n; i++) {
		int cn = query(num[i], num[i]);
		sum += cn * (cn - 1) / 2;
		for (int j = 1; j*num[i] - 1 <= num[n]; j++) {
			int var = query(j * num[i] + (j == 1), (j + 1) * num[i] - 1);
			sum += cn * var * j;
		}
	}
	printf("%lld",sum);
}