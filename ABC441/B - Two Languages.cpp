#include <bits/stdc++.h>
using namespace std;
int n, m, q;
string s1, s2;
bool a[30], b[30], c[30];
string str;
int main() {
	cin >> n >> m >> s1 >> s2;
	for (int i = 0; i < n; i++)
		a[s1[i] - 'a'] = 1;
	for (int i = 0; i < m; i++)
		b[s2[i] - 'a'] = 1;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> str;
		for (int i = 0; i < 26; i++) c[i] = 0;
		for (char ch : str) c[ch - 'a'] = 1;
		bool found[2] = {true, true};
		for (int i = 0; i < 26; i++) {
			if (a[i] == 0 && c[i]) found[0] = 0;
			if (b[i] == 0 && c[i]) found[1] = 0;
		}
		if (found[0]^found[1]) {
			if (found[0]) puts("Takahashi");
			if (found[1]) puts("Aoki");
		} else puts("Unknown");
	}
}