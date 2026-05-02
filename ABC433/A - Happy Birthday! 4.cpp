#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main() {
	cin >> x >> y >> z;
	if (x < y) puts("No");
	else if (x == y * z) puts("Yes");
	else if ((y * z - x) % (1 - z)) puts("No");
	else if((y*z-x)/(1-z)>=0) puts("Yes");
	else puts("No");
}
