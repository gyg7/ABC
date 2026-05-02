#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, m, a[N], len[N], pw[11], num[11];
long long ans;
unordered_map<int, int> unmap[11];
int main() {
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i <= 10; i++)
		pw[i] = (pw[i - 1] * 10)%m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int p = a[i]; p; p /= 10)
			++len[i];
		num[len[i]] = 1;
		a[i] %= m;
	}
	for (int i = 1; i <= n; i++){
		unmap[len[i]][((-a[i])%m + m) % m]++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 10; j++) {
			if(num[j]==0) continue;
			int x = (1ll*a[i]  * pw[j]) % m;
			ans += unmap[j][(x + m) % m];
		}
	cout << ans << endl;
}
