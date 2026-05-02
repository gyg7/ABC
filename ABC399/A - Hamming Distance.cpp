#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s, t;
int main() {
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i]) ans++;
cout<<ans<<endl;
	return 0;
}