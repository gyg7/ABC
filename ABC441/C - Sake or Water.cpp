#include <bits/stdc++.h>
using namespace std;
long long n, k, x, a[300001];
long long sum;
int main() {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i=k; i >= 1; i--) {
        sum+=a[i];
		if (sum >= x) {
			cout <<n-i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}