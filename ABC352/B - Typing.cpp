#include <bits/stdc++.h>
using namespace std;
string s, t;
int i;
int main() {
	cin >> s >> t;
	for (int j = 0; t[j]; j++)
		if (s[i] == t[j]) {
			printf("%d ", j+1);
			++i;
		}
}