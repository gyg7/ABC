#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
int main() {
	for (int i = 1; i <= 12; i++) {
		cin >> s;
		ans += (s.length() == i);
	}
	cout << ans << endl;
}