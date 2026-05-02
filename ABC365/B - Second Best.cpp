#include <bits/stdc++.h>
using namespace std;
int n, x[101], mx, mxx;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (x[i] > x[mx]) {
			mxx = mx;
			mx = i;
		} else if (x[i] > x[mxx])
			mxx = i;
	}
	printf("%d",mxx);
}