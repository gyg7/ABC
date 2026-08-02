#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		if (n == i * 111) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}