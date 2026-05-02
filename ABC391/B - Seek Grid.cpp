#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[51][51], t[51][51];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> s[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			cin >> t[i][j];
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = 1; j <= n - m + 1; j++) {
			bool flag = 1;
			for (int ii = 1; ii <= m; ii++)
				for (int jj = 1; jj <= m; jj++)
					if (s[i + ii - 1][j + jj - 1] != t[ii][jj]) {
						flag = 0;
						goto bh;
					}
		bh:
			if (flag) 
				return printf("%d %d", i, j),0;
		}
	}
}