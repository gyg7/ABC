#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= 31; i++)
		if (n < (1 << i)-1) {
			printf("%d", i);
			return 0;
		}
	return 0;
}