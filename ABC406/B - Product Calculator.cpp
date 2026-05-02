#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
int n, k;
long long a;
ll  ten, res = 1;
void write(ll x) {
	if (x / 10) write(x / 10);
	putchar('0' + x % 10);
}
int main() {
	cin >> n >> k;
	ten = 1;
	for (int i = 1; i <= k; i++) ten = ten * 10;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (res * a >= ten)
			res = 1;
		else res *= a;
	}
	write(res);
	return 0;
}
