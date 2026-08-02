#include <bits/stdc++.h>
using namespace std;
char ch;
int res;
int main() {
	while (cin >> ch) {
		if (ch == 'i' || ch == 'j') ++res;
	}
	cout << res << endl;
}