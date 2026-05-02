#include <bits/stdc++.h>
using namespace std;
string str;
int cnt, old = 0;
int main() {
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (old == (str[i] == 'i' ? 1 : 0)) cnt++;
		old = str[i] == 'i' ? 1 : 0;
	}
	if (old) cnt++;
	cout << cnt << endl;
	return 0;
}
