#include <bits/stdc++.h>
using namespace std;
int n, d, ans;
char ch[110];
int p[210];
int main() {
	scanf("%d%d%s", &n, &d, ch + 1);
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 'G') p[max(0, i - d)]++, p[min(n+1, i + d + 1)]--;
	}
	for (int i = 1; i <= n; i++) {
		p[i] += p[i - 1];
		if (p[i] == 0&&ch[i]=='.'){
            ++ans;
            }
	}
	cout << ans << endl;
	return 0;
}