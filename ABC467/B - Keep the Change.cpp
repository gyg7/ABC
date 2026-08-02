#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		
		if (s == "keep") {x += a;
			y += b;
		}
	}
	cout << y - x << endl;
	return 0;
}