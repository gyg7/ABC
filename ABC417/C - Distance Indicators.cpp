#include <bits/stdc++.h>
using namespace std;
/*
j-i=ai+aj
j-aj=ai+i
*/
long long n, a, ans;
map<int, int> mp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans += mp[i - a];
		mp[a + i]++;
	}
cout<<ans;
	return 0;
}
