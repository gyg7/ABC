#include <bits/stdc++.h>
using namespace std;
string s, t;
int lst, lst2;
int main() {
	cin >> s;
	t = s;
	lst = -2;
lst2=-1;
	for (int i = 0; t[i]; i++) {
		if (t[i] == '.')
			if (lst < lst2) {
				t[i] = 'o';
				lst = i;
			}
		if (t[i] == '#') lst2 = i;
	}
	if (lst2 == -1) t[0] = 'o';
	cout << t << endl;
	return 0;
}
