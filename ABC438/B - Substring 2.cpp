#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int main() {
	cin >> n >> m >> a >> b;
	int ans = 0x3f3f3f3f;
	for (int i = 0; i + m - 1 < n; i++) {
		int sum  = 0;
		for (int j = 0; j < m; j++)
			sum += (a[i + j] - b[j] + 10) % 10;
		ans = min(ans, sum);
	}
	cout << ans << endl;
}