#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	if (400 % n == 0) cout << 400 / n << endl;
	else cout << -1 << endl;
	return 0;
}