#include <bits/stdc++.h>
using namespace std;
int n;
char ch[110];
int main() {
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("No");
		return 0;
	}
	scanf("%s", (ch + 1));
	if (ch[(n + 1) / 2] != '/') {
		printf("No");
		return 0;
	}
	for (int i = 1; i <= (n + 1) / 2 - 1; i++) {
		if (ch[i] == '2') {
			printf("No");
			return 0;
		}
	}
	for (int i = (n + 1) / 2 + 1; i <= n; i++) {
		if (ch[i] == '1') {
			printf("No");
			return 0;
		}
	}
	puts("Yes");
}