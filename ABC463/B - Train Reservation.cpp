#include <bits/stdc++.h>
using namespace std;
int n;
char ch;
string s;
int main() {
	cin >> n >> ch;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (s[ch - 'A'] == 'o') {
			printf("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}