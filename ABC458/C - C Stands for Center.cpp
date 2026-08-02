#include <bits/stdc++.h>
using namespace std;
string s;
long long ans;
int n;
int main() {
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			int p = min(i, n - i-1);
			ans += p +1;
		}
	}
	cout << ans << endl;
}