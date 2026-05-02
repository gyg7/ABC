#include <bits/stdc++.h>
using namespace std;
int n, s, told, tnew;
int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> tnew;
		if (told + s < tnew) {
			printf("No");
			return 0;
		}
		told = tnew;
	}
	cout << "Yes" << endl;
	return 0;
}
