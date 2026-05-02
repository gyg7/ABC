#include <bits/stdc++.h>
using namespace std;
int n, k;
string s, t;
vector<pair<int, int>> ve;
int l[500001], r[500001];
int main() {
	cin >> n >> k >> s;
	t = string(n + 1, ' ');
	s = " " + s;
	for (int i = 1; s[i];) {
		if (s[i] == '1') {
			int j = i;
			while (s[j + 1] && s[j + 1] == s[i]) j++;
			ve.push_back({i, j});
			i = j + 1;
		} else i++;
	}
	for (int i = 0; i < k; i++) {
		l[i + 1] = ve[i].first;
		r[i + 1] = ve[i].second;
	}
	for (int i = k; i <= k; i++) {
		for (int j = 1; j <= r[i - 1]; j++)
			t[j] = s[j];
		for (int j = r[i - 1] + 1; j <= r[i - 1] + (r[i] - l[i]) + 1; j++)
			t[j] = '1';
		for (int j = r[i - 1] + (r[i] - l[i]) + 2; j <= r[i]; j++)
			t[j] = '0';
		for (int j = r[i] + 1; j <= n; j++)
			t[j] = s[j];
	}
	for (int i = 1; i <= n; i++)
		cout << t[i];
}