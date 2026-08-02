#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2, ans3, mx1, mx2, mx3;
int main() {
	cin >> n;
	mx1 = mx2 = mx3 = 200;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (mx1 > x) {
			mx3 = mx2;
			mx2 = mx1;
			mx1 = x;
			ans3 = ans2;
			ans2 = ans1;
			ans1 = i;
		} else if (mx2 > x) {
			mx3 = mx2;
			mx2 = x;
			ans3 = ans2;
			ans2 = i;
		} else if (mx3 > x) {
			mx3 = x;
			ans3 = i;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
}