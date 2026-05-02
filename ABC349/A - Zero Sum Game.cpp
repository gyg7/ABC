#include <bits/stdc++.h>
using namespace std;
int n, a, sum;
int main() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a;
		sum += a;
	}
	printf("%d", -sum);
}