#include <bits/stdc++.h>
using namespace std;
string s;
int num[30], tot, max_;
int main() {
	cin >> s;
	sort(s.begin(), s.end());
	num[tot = 1] = 1;
	for (int i = 1; s[i]; i++) {
		if (s[i - 1] != s[i]) tot++;
		num[tot]++;
	}
	for (int i = 1; i <= tot; i++) if (num[i] > max_) max_ = num[i];
	for (int i = 1; i <= max_; i++) {
		int cnt = count(num + 1, num + tot + 1, i);
		if (cnt != 0 && cnt != 2) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}