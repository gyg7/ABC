#include <bits/stdc++.h>
using namespace std;
int n, a, x, mp[101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		mp[a]++;
	}
	cin >> x;
	printf(mp[x] ? "Yes" : "No");
	return 0;
}
