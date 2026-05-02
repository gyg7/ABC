#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	int n = s.length(), ans = 0;
	s = "^" + s + "$";
	for (int i = 1; i <= n; i++)
		if (s[i] + 1 == s[i + 1])
			for (int l = 1; 0 <= i - l + 1 && i + 1 + l - 1 <= n+1; l++)
				if (s[i - l + 1] != s[i] || s[i + 1] != s[i + 1 + l - 1]) {
					ans += l-1;
					break;
				}
	cout << ans << endl;
}