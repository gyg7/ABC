#include <bits/stdc++.h>
using namespace std;
int p[101], x;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		p[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (p[i] != x) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
