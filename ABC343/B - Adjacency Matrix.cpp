#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (a) printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}