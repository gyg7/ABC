#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
	cin >> s1 >> s2;
	if (s1 == "sick") {
		if (s2 == "sick") cout << 1 << endl;
		else cout << 2 << endl;
	} else {
		if (s2 == "sick") cout << 3 << endl;
		else cout << 4 << endl;
	}
	return 0;
}