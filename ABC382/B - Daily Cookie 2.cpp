#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
char ch[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> ch[i];
	for (int i = n; i >= 1; i--) {
		if (ch[i] == '@' && m) {
			ch[i] = '.';
			m--;
		}
	}
	printf("%s", (ch + 1));
	return 0;
}