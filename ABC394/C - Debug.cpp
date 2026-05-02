#include <bits/stdc++.h>
using namespace std;
string s;
int sk[300001], top;
int main() {
	cin >> s;
	for (int i = 0; s[i]; i++) {
		sk[++top] = i;
		while (i >= 1 && s[sk[top]] == 'A' && s[sk[top] - 1] == 'W') {
			s[sk[top]] = 'C';
			s[sk[top] - 1] = 'A';
			top -= 1;
		}
	}
	cout << s << endl;
	return 0;
}