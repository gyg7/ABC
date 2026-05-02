#include <bits/stdc++.h>
using namespace std;
int a[4], sum[1 << 4], u;
int main() {
	for (int i = 1; i <= 3; i++)
		cin >> a[i];
	u = (1 << 3) - 1;
	if (a[1] == a[2] && a[2] == a[3]) {
		cout << "Yes";
		return 0;
	}
	for (int i = 1; i <= u - 1; i++)
		for (int j = 1; j <= 3; j++)
			if (i & (1 << (j - 1)))
				sum[i] += a[j];
	for (int i = 1; i <= u - 1; i++) {
		if (sum[i] == sum[u ^ i]) {
			printf("Yes");
			return 0;
		}
	}
	puts("No");
}