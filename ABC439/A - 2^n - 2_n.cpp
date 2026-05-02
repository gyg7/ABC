#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	int ans = (1 << n) - 2 * n;
	cout << ans << endl;
}