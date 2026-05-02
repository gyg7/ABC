#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], s, sum, suf[200002], pre[200002];
unordered_set<long long> se;
int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] + a[i];
	// (s-pre[i]-suf[j])%sum==0 ==> (s-pre[i]) === suf[j] (mod sum)
	for (int i = 0; i <= n; i++)
		se.insert((s-pre[i]%sum+sum)%sum);
	for (int i = 0; i <= n; i++)
		if (se.count(suf[i])) {
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}