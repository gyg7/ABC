#include <bits/stdc++.h>
using namespace std;
int x;
string s = "HelloWorld";
int main() {
	cin >> x;
	for (int i = 0; i < 10; i++) {
		if (i == x - 1) continue;
		putchar(s[i]);
	}
}
