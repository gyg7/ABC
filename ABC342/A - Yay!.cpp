#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
	cin >> str;
	for (int i = 0; str[i]; i++)
		if (count(str.begin(), str.end(), str[i]) == 1) {
			cout << i + 1;
			return 0;
		}
	return 0;
}