#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int ans = 0;
			if (i > 1) ans++;
			if (i < h) ans++;
			if (j > 1) ans++;
			if (j < w) ans++;
			cout << ans << (j == w ? '\n' : ' ');
		}
	}
}
