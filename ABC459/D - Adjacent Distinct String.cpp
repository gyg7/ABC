#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int mx = 0, chs = 0, n = s.length();
		for (auto ch : s) {

			cnt[ch - 'a']++;
			if (mx < cnt[ch - 'a']) {
				mx = cnt[ch - 'a'];
				chs = ch;
			}
		}
		if (2 * mx > n + 1) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (int i = 0; i < n; i++) s[i] = '*';
			for (int i = 0; 2 * i < n && i < mx; i++) {
				s[2 * i] = chs;
			}
			cnt[chs - 'a'] = 0;
			int cur = 0;
			for (int i = 0; i < 26; i++) {
				if (cnt[cur + i]) {
					cur += i;
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				if (s[i] == '*') {
					s[i] = cur + 'a';
					cnt[cur]--;
					for (int i = 1; i < 26; i++) {
						if (cnt[(cur + i) % 26]) {
							cur = (cur + i) % 26;
							break;
						}
					}
				}
			}
			cout << s << endl;
		}

	}
}
