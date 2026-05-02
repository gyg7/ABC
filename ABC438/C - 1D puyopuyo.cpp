#include <bits/stdc++.h>
using namespace std;
int st[200001], top, n, x;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (top >= 3 && st[top] == x && st[top - 1] == x && st[top - 2] == x) {
			top -= 3;
		} else st[++top] = x;
	}
	cout << top << endl;
}