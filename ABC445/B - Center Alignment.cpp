#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		m = max(m, (int)s[i].size());
	}
	for (int i = 1; i <= n; i++) {
		int k = (m - (int)s[i].size()) / 2;
		for (int i = 0; i < k; i++) putchar('.');
		cout << s[i];
		for (int i = 0; i < k; i++) putchar('.');
		puts("");
	}
}