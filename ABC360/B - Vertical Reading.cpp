#include <bits/stdc++.h>
using namespace std;
string s, t;
int n;
bool cmp( int c, int k) {
	for (int i = 0; s[i * c + k] || t[i]; i++)
		if (s[i * c + k] != t[i])
			return 0;
	return 1;
}
int main(void) {
	cin >> s >> t;
	n = s.length();
	for (int c = 1; c < n; c++) {
		bool ok = 1;
		for (int k = 0; k < c; k++)
			if (cmp(c, k)) {
				ok = 0;
				break;
			}
		if (ok == 0) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}