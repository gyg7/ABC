#include <bits/stdc++.h>
using namespace std;
int n, a[101], k, ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 1; i <= n; i++)
		if (k <= a[i]) ++ans;
cout<<ans<<endl;
	return 0;
}
