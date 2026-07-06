#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n, m, a[N], b[N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int j = 1;
	for (int i = 1; i <= n; i++)
		if (j <= m && b[j] <= a[i] * 2) ++j;
	cout << j - 1 << endl;
}
