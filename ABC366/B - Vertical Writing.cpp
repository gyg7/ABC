#include <bits/stdc++.h>
using namespace std;
int n;
char ch[103][104];
int main() {
	cin >> n;
	getchar();
	for (int j = n; j >= 1; j--)
		for (int i = 1; i <= 101; i++) {
			ch[i][j] = getchar();
			if (ch[i][j] == '\n') {
				ch[i][j] = '\0';
				break;
			}
		}
	for (int j = n; j >= 1; j--)
		for (int i = 100; i >= 1; i--)
			if (islower(ch[i][j]))
				for (int k = j - 1; k >= 1; k--)
					if (!ch[i][k])
						ch[i][k] = '*';
	for (int i = 1; i <= 100; i++) {
		if (ch[i][1] == '\0') break;
		for (int j = 1; j <= n; j++)
			if (ch[i][j])
				putchar(ch[i][j]);

		putchar('\n');
	}
}