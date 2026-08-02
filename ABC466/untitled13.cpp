#include <bits/stdc++.h>
using namespace std;
int n, last, ans;
int main() {
	cin >> n;
	last = 1;
	for (int i = 1; i <= n; i++) {
		int l = last + 1, r = n, pos = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			cout << "? " << i << " " << mid << endl;
			string s;
			cin >> s;
			if (s == "Yes") {
				pos = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		last = pos;
		ans += last - i;
	}
	cout << "! " << ans << endl;
	return 0;
}
