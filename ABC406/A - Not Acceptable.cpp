#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	if (c * 60 + d <= a * 60 + b) puts("Yes");
	else puts("No");
	return 0;
}
