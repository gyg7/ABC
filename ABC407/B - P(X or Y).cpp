#include <bits/stdc++.h>
using namespace std;
int x, y, ans;
int main() {
	cin >> x >> y;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (i + j >= x || abs(i - j) >= y) ans++;
	printf("%.10lf", (double)ans * 1.0 / 36);
	return 0;
}
