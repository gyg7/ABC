#include <bits/stdc++.h>
using namespace std;
string str;
int ans, n, a[10000001];
int main() {
	cin >> str;
	for (int i = 0; str[i]; i++) {
		a[i + 1] = str[i] - '0';
	}
	n = str.length();
	for (int i = 1; i <= n; i++) {
		ans++;
		ans += (a[i] - a[i + 1] + 10) % 10;
	}
	cout << ans << endl;
	return 0;
}
