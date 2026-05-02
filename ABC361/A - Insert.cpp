#include <bits/stdc++.h>
using namespace std;
int n, k, a[101], x;
int main(void) {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= k; i++)
		cout << a[i] << " ";
	cout << x << " ";
	for (int i = k + 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
