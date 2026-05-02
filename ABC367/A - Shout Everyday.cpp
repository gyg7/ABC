#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	if (c < b) c += 24;
	for (int i = -1; i <= 1; i++)
		if (24 * i + b <= a && a <= 24 * i + c) {
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}
