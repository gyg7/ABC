#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	if (n % 2 == 1) {
		for (int i = 1; i <= n / 2; i++)
			printf("-");
		printf("=");
		for (int i = n / 2 + 2; i <= n; i++)
			printf("-");
	} else {
		for (int i = 1; i <= n / 2 - 1; i++)
			printf("-");
		printf("==");
		for (int i = n / 2 + 2; i <= n; i++)
			printf("-");
	}
	return 0;
}