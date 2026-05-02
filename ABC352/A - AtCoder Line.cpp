#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
int main() {
	cin >> n >> x >> y >> z;
	if (x > y) swap(x, y);
	if (x <= z && z <= y) printf("%s", "Yes");
	else printf("No");
}