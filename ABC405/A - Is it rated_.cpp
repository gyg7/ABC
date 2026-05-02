#include <bits/stdc++.h>
using namespace std;
int r, x;
int main() {
	cin >> r >> x;
	if (1600 <= r && r <= 2999 && x == 1) puts("Yes");
	else if (1200 <= r && r <= 2399 && x == 2) puts("Yes");
	else puts("No");
	return 0;
}
