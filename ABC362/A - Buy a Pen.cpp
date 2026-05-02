#include <bits/stdc++.h>
using namespace std;
int r, g, b;
string str;
int main() {
	cin >> r >> g >> b >> str;
	if (str == "Red")
		cout << min(g, b);
	if (str == "Green")
		cout << min(r, b);
	if (str == "Blue")
		cout << min(r, g);

	return 0;
}
