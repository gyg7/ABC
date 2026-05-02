#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
	cin >> n >> a;
	for (int i = 1; i < n; i++) {
		cin >> b;
		if (a >= b)
			return printf("No"), 0;
		a = b;
	}
	printf("Yes");
	return 0;
}