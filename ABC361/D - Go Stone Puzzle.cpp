#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> node;
int n;
string s, t;
map<string, int> mp, st;
queue<node> que;
vector<string> change(string s) {
	vector<string> ve;
	int u = -1;
	for (int i = 0; i <= n; i++)
		if (s[i] == '.') {
			u = i;
			break;
		}
	for (int i = 0; i <= n; i++) {
		if (s[i] != '.' && s[i + 1] != '.') {
			swap(s[i], s[u]);
			swap(s[i + 1], s[u + 1]);
			ve.push_back(s);
			swap(s[i], s[u]);
			swap(s[i + 1], s[u + 1]);
		}
	}
	return ve;
}
int main(void) {
	cin >> n;
	cin >> s >> t;
	s = s + "..";
	t = t + "..";
	if (count(s.begin(), s.end(), 'B') != count(t.begin(), t.end(), 'B') || count(s.begin(), s.end(), 'W') != count(t.begin(), t.end(), 'W')) {
		printf("-1");
		return 0;
	}
	que.push({s, st[s] = 0});
	while (que.size()) {
		auto [o, ste] = que.front();
		que.pop();
		if (o == t) {
			cout << ste << endl;
			return 0;
		}
		if (mp[o] == 1)  continue;
		mp[o] = 1;
		for (string v : change(o))
			que.push({v, ste + 1});
	}
	printf("-1\n");
	return 0;
}
