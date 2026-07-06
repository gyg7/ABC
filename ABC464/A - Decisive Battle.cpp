#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[2];
int main() {
	cin >> s;
	for (char ch : s) {
		cnt[ch == 'W']++;
	}
	puts(cnt[0] > cnt[1] ? "East" : "West");
	return 0;
}