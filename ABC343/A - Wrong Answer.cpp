#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; i <= 9; i++) 
		if (i != a + b) {
			cout << i << endl;
			return 0;
		}
	return 0;
}