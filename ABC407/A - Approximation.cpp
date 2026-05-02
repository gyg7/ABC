#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b;
	c = a / b;
	a %= b;
	if (a * 2 > b) c++;
	cout << c << endl;
	return 0;
}
