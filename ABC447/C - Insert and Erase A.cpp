#include <bits/stdc++.h>
using namespace std;
string a, b, aa, bb;
int A, B, ans;
int main() {
	cin >> a >> b;
	for (char ch : a)
		if (ch != 'A') aa.push_back(ch);
	for (char ch : b) if (ch != 'A')bb.push_back(ch);
	if (aa != bb) {
		puts("-1");
		return 0;
	}
	int i = 0, j = 0;
	for (int _ = 0;; _++) {
		while (i < a.size() && a[i] == 'A') {
			A++;
			++i;
		}
		while (j < b.size() && b[j] == 'A') {
			B++;
			++j;
		}
		ans += abs(A - B);
		i++, j++;
		if (i >= a.size() && j >= b.size()) break;
		A = B = 0;
	}
	cout << ans << endl;
}