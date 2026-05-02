#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int ans, n;
string s;
int main() {
	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + i - 1 < n; j++) {
			if (mp.count(s.substr(j, i)) == 0)
				ans++;
			mp[s.substr(j, i)] = 1;
		}
	}
	printf("%d",ans);
}