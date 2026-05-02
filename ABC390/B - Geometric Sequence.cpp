#include <bits/stdc++.h>
using namespace std;
int n;
long long a[101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i < n; i++)
		if (a[i - 1]*a[i + 1] != a[i]*a[i]) {
			puts("No");
			return 0;
		}
	puts("Yes");
}