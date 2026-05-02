#include <bits/stdc++.h>
using namespace std;
int n, l, r;
char ch;
vector<int> ve[26];
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		ve[ch - 'a'].push_back(i);
	}
	long long ans = 0;
	for (int ch = 0; ch < 26; ch++) {
		int sz = ve[ch].size(), j = 0, k = 0;
		for (int i = 0; i < sz; i++) {
			while(ve[ch][i] - ve[ch][j] > r) j++;
			while(ve[ch][i] - ve[ch][k] >= l) k++;
			ans += k - j;
		}
	}
	cout << ans << endl;
}