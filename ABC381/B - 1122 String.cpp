#include <bits/stdc++.h>
using namespace std;
#define no {printf("No"); return 0;}
char ch[111];
int n, cnt[255];
int main() {
	scanf("%s", (ch + 1));
	n = strlen(ch + 1);
	if (n % 2) no;
	for (int i = 1; (i << 1) <= n; i++)
		if (ch[2 * i - 1] != ch[2 * i])
			no;
	for (int i = 1; i <= n; i++) {
		cnt[ch[i]]++;

	}
	for (int i = 1; i <= n; i++)
		if (cnt[ch[i]] >= 3 || cnt[ch[i]] == 1)
			no;
	printf("Yes");

}