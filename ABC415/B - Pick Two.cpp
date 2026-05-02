#include <bits/stdc++.h>
using namespace std;
string s;
int d[1001], tot;
int main() {
	cin >> s;
	for (int i = 0; s[i]; i++)
		if (s[i] == '#') d[++tot] = i + 1;
	for (int i = 1; 2 * i <= tot; i++)
		printf("%d,%d\n", d[2 * i - 1], d[2 * i]);
	return 0;
}
