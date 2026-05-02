#include <bits/stdc++.h>
using namespace std;
long long n, m, k, sum;
int main() {
	k = 1;
	cin >> n >> m;
	for (int i = 0; i <= m; i++) {
		if (sum > 1000000000 - k) {
			printf("inf");
			return 0;
		}
		sum += k;
		k *= n;
	}
	cout << sum << endl;
	return 0;
}