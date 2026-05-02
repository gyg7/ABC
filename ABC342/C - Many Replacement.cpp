#include<bits/stdc++.h>
using namespace std;
int n, q, fa[27];
string s;
char c, d;
int main() {
	cin >> n >> s >> q;
	for (int i = 1; i <= 26; i++)
		fa[i] = i;
	for (int i = 1; i <= q; i++) {
		cin >> c >> d;
		for (int i = 1; i <= 26; i++)
			if (fa[i] == c - 'a' + 1)
				fa[i] = d - 'a' + 1;
	}
	for (int i = 0; s[i]; i++) {
		c  = fa[s[i] - 'a' + 1] + 'a' - 1;
		printf("%c", c);
	}
	return 0;
}