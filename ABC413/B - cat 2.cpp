#include <bits/stdc++.h>
using namespace std;
int n;
string s[101];
unordered_set<string> se;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) se.insert(s[i] + s[j]);
	cout << se.size() << endl;
	return 0;
}
