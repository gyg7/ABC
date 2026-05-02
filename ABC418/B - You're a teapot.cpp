#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> pos;
double ans;
int main() {
	cin >> s;
	for (int i = 0; s[i]; i++)
		if (s[i] == 't') pos.push_back(i);

	for (int i : pos) {
		int cnt = 0;
		for (int j : pos) {
			if (i <= j) ++cnt;
			if (j - i + 1 < 3) continue;

			ans = max(ans, (double)(cnt - 2) / (j - i + 1 - 2));
		}
	}
	printf("%.9f", ans);
	return 0;
}
