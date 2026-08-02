#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			if ((i == 0 || s[i - 1] == 'x') && (i == n - 1 || s[i + 1] == 'x'))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}