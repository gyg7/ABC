#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'o') {
			for (int j = i; j < n; j++) putchar(s[j]);
			return 0;
		}
	}
	return 0;
}