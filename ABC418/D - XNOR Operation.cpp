#include <bits/stdc++.h>
using namespace std;
long long n, p[200001], ans;
string s;
int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		bool bit = s[i - 1] - '0';
		p[i] = !(p[i - 1] ^ bit);
	}
long long cnt[2] = {1, 0};
	for (int i = 1; i <= n; i++) {
		ans += cnt[p[i]];
		cnt[p[i]]++;
	}
	cout << ans << endl;
	return 0;
}
