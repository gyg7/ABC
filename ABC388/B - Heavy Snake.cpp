#include <bits/stdc++.h>
using namespace std;
int n, d, a[101], b[101];
int p;
int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= d; i++) {
		p = 0;
		for (int j = 1; j <= n; j++)
			if (p < a[j] * (b[j] + i)) p = a[j] * (b[j] + i);
		cout << p << endl;
	}
	return 0;
}