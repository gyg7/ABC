#include <bits/stdc++.h>
using namespace std;
int n, ans, a[300001], res;
unordered_map<int, int> mp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ans = -1;
	for (int i = n; i >= 1; i--)
		if (mp[a[i]] == 1) {
			if (res < a[i]) {
				res = a[i];
				ans = i;
			}
		}
	printf("%d", ans);
	return 0;
}