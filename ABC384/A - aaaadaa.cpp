#include <bits/stdc++.h>
using namespace std;
int n;
char c1, c2, c3;
int main() {
	cin >> n >> c1 >> c2;
	for (int i = 1; i <= n; i++) {
		cin >> c3;
		if (c3 == c1) putchar(c1);
		else putchar(c2);
	}
	return 0;
}