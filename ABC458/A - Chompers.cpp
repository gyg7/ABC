#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
	cin >> s >> n;
	int m = s.length();
	for (int i = 0; i < m; i++) {
		if (i < n || i >= m - n) continue;
		putchar(s[i]);
	}
}