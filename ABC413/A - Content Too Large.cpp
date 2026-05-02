#include <bits/stdc++.h>
using namespace std;
int n, m, x, sum;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
	}
	sum <= m ? printf("Yes") : printf("No");
	return 0;
}
