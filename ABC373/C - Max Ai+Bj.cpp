#include <bits/stdc++.h>
using namespace std;
int n, x;
long long a=-1e9, b=-1e9;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x > a) a = x;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x > b) b = x;
	}
	cout << a + b << endl;
}