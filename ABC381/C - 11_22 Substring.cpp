#include <bits/stdc++.h>
using namespace std;
int n, ans;
char ch[200001];
int main() {
	scanf("%d", &n);
	scanf("%s", (ch + 1));
	for (int key = 1; key <= n; key++)
		if (ch[key] == '/')
			for (int i = 1; i <= n; i++)
				if ((key - i >= 0 && ch[key - i] != '1') || (key + i <= n + 1 && ch[key + i] != '2')) {
					ans = max(ans, 2 * (i - 1) + 1);
					break;
				}
	printf("%d\n", ans);
}