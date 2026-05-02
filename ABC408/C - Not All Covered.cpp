#include <bits/stdc++.h>
using namespace std;
int n, m, l[200001], r[200001];
int a[1000001], mn;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
		a[l[i]]++;
		a[r[i] + 1]--;
	}
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	mn = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		if (a[i] < mn) mn = a[i];
	cout << mn << endl;
	return 0;
}
