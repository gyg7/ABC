#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a, b, c;
bool vis[1000001];
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') a.push_back(i);
		if (s[i] == 'B') b.push_back(i);
		if (s[i] == 'C') c.push_back(i);
	}
	int j = 0, k = 0, ans = 0;
	for (int i = 0; i < a.size(); i++) {
		while (j < b.size() && b[j] < a[i]) j++;
		while (j < b.size() && vis[b[j]]) j++;
		if (j == b.size()) break;
		vis[b[j]] = 1;
		while (k < c.size() && c[k] < b[j]) k++;
		while (k < c.size() && vis[c[k]]) k++;
		if (k == c.size()) break;
		vis[c[k]] = 1;
		++ans;
	}
	cout << ans << endl;
}