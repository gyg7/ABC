#include <bits/stdc++.h>
using namespace std;
int h, w, ans;
char g[15][15];
int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin>>g[i][j];
	for (int x1 = 1; x1 <= h; ++x1)
		for (int y1 = 1; y1 <= w; ++y1)
			for (int x2 = x1; x2 <= h; ++x2)
				for (int y2 = y1; y2 <= w; ++y2)
				{
					bool ok = 1;
					for (int k1 = x1; k1 <= x2; ++k1)
						for (int k2 = y1; k2 <= y2; ++k2) {
							if (g[k1][k2] != g[x1 + x2 - k1][y1 + y2 - k2]) {
								ok = 0;
								break;
							}
						}
					ans += ok;
				}
	cout << ans << endl;
}
