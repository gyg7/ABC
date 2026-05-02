#include <bits/stdc++.h>
using namespace std;
string s, t;
int n;
int main() {
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o' && t[i] == 'o') {
			cout << "Yes" << endl;
return 0;
		}
	}
puts("No");
	return 0;
}
