#include <bits/stdc++.h>
using namespace std;
int bits[] = {1, 3, 9, 27, 81, 243, 729};
int n;
char ch[730][730];
void dfs(int x, int y, int k) {
	if (k == 0) {
		ch[x][y] = '#';
		return;
	}
	dfs(x, y, k - 1);
	dfs(x + bits[k-1], y, k - 1);
	dfs(x + bits[k-1] * 2, y, k - 1);
	dfs(x, y + bits[k-1], k - 1);
	dfs(x + bits[k-1] * 2, y + bits[k-1], k - 1);
	dfs(x, y + bits[k-1] * 2, k - 1);
	dfs(x + bits[k-1], y + bits[k-1] * 2, k - 1);
	dfs(x + bits[k-1] * 2, y + bits[k-1] * 2, k - 1);

}
int main() {
	cin >> n;
	memset(ch, '.', sizeof ch);
	dfs(1, 1, n);
	for (int i = 1; i <= bits[n]; i++) {
		for (int j = 1; j <= bits[n]; j++)
			printf("%c", ch[i][j]);
		putchar('\n');
	}
}