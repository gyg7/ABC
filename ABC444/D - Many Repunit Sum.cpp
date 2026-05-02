#include <bits/stdc++.h>
using namespace std;
int n, a, s[200011];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		s[a - 1]++;
	}
	for (int i = 200000; i >= 0; i--)
		s[i] += s[i + 1];
	for (int i = 0; i < 200000; i++) {
		s[i + 1] += s[i] / 10;
		s[i] %= 10;
	}
	for (int i = 200000; i >= 0; --i)
		if (s[i]) {
			for (int j = i; j >= 0; j--)
				cout << s[j];
			return 0;
		}
	return 0;
}