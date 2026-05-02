#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	if (a > b) swap(a, b);
	if (a == 1 && b == 2) cout << 3;
	else if (a == 1 && b == 3) cout << 2;
	else if (a == 2 && b == 3) cout << 1;
	else cout << -1;
	return 0;
}