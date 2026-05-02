#include <bits/stdc++.h>
using namespace std;
int n;
string s, t = "tea";
int main() {
	cin >> n >> s;
	if (n <= 2) {
		puts("No");
		return 0;
	}
	if (s[n - 1] == 'a' && s[n - 2] == 'e' && s[n - 3] == 't') {
		puts("Yes");
	} else puts("No");
	return 0;
}
