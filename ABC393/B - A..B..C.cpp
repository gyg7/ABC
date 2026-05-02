#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
int main() {
	cin >> s;
	int l = s.length();
	for (int len = 2; len <= l; len++)
		for (int i = len - 1; i + len - 1 <= l; i++)
			if (s[i - len + 1] == 'A' && s[i] == 'B' && s[i + len - 1] == 'C')
				ans++;
	cout << ans << endl;
	return 0;
}