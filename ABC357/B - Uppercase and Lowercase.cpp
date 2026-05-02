#include <bits/stdc++.h>
using namespace std;
string str;
int low, upp;
int main() {
	cin >> str;
	for (char ch : str) {
		if (isupper(ch)) upp++;
		if (islower(ch)) low++;
	}
	if (upp > low)
		for (char ch : str)
			putchar(toupper(ch));
	else
		for (char ch : str)
			putchar(tolower(ch));
}