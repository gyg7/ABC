#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
	cin >> s >> t;
	for (int i = 1; s[i]; i++) {
		if (isupper(s[i])) {
			if (!count(t.begin(), t.end(), s[i - 1])) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
