#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	for (auto ch : s) 
		if (isupper(ch)) cout << ch;
	return 0;
}