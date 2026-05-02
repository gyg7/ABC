#include <bits/stdc++.h>
using namespace std;
#define int long long
string str;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> str;
	if (str == "red") cout << "SSS" << endl;
	else if (str == "blue") cout << "FFF" << endl;
	else if (str == "green") cout << "MMM" << endl;
	else cout << "Unknown" << endl;
	return 0;
}

