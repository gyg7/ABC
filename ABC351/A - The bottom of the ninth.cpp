#include <bits/stdc++.h>
using namespace std;
int x, a, b;
int main() {
	for (int i = 1; i <= 9; i++) {
		cin >> x;
		a += x;
	}
	for (int i = 1; i <= 8; i++) {
		cin >> x;
		b += x;
	}
	printf("%d", max(0, a - b + 1));
}