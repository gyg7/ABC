#include <bits/stdc++.h>
using namespace std;
int n, m, x;
char opt;
bool vis[101];
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> opt;
		if (opt == 'M' && vis[x] == 0) {
			printf("Yes\n");
			vis[x] = 1;
		} else printf("No\n");
	}
}