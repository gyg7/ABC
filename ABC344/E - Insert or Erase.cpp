#include <bits/stdc++.h>
using namespace std;
int n, m, cmd, x, y, tot;
struct node {
	int val,  ls, rs;
} a[4000001];
map<int, int> mp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = {x, i - 1, i + 1};
		mp[x] = i;
	}
	a[0].rs = 1;
	a[n].rs = 0;
	tot = n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cmd >> x;
		if (cmd == 1) {
			cin >> y;
			mp[y] = ++tot;
			a[tot] = {y, mp[x], a[mp[x]].rs};
			a[a[mp[x]].rs].ls = tot;
			a[mp[x]].rs = tot;
		} else {
			a[a[mp[x]].ls].rs = a[mp[x]].rs;
			a[a[mp[x]].rs].ls = a[mp[x]].ls;
			mp[x] = 0;
		}
	}
	for (int i = a[0].rs; i; i = a[i].rs)
		printf("%d ", a[i].val);
}