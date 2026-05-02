#include <bits/stdc++.h>
using namespace std;
int n, y, s;
int main() {
	cin >> n >> y >> s;
	if (y + (n - (y + s)) > s&&s+(n-(y+s))>y) {
		printf("No");
	} else printf("Yes");

	return 0;
}