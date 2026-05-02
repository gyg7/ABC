#include <bits/stdc++.h>
using namespace std;
char a, b, c;
string pd() {
	if (a == 'R' && (b == 'M' || c == 'M'))
		return "Yes";
	if (b == 'R' && c == 'M') return "Yes";
	else return "No";
}
int main(void) {
	cin >> a >> b >> c;
	cout << pd() << endl;
	return 0;
}