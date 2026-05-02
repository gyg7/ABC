#include <bits/stdc++.h>
using namespace std;
int n;
char ch[51][51];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int j = n - i + 1;
		char g = (i % 2 ? '#' : '.');
		for (int k = i; k <= j; k++)
			for (int l = i; l <= j; l++)
				ch[k][l] = g;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%c", ch[i][j]);
		puts("");
	}
	return 0;
}