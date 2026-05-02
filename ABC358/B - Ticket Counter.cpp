#include <bits/stdc++.h>
using namespace std;
int n, a, j, b[101];
long long ans;
int main() {
	cin >> n >> a;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	b[n + 1] = INT_MAX;
	int j = 1;
	ans = b[1];
	for (int i = 2; i <= n + 1; i++)
		while (b[i] - b[j] >= a) {
			ans += a;
			printf("%lld\n", ans);
			j++;
			if (ans < b[j])
				ans = b[j];
		}

}