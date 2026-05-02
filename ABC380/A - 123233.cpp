#include <bits/stdc++.h>
using namespace std;
int count(int x, int d) {
	int res = 0;
	for (int i = 1; i <= 1000000; i *= 10)
		if (x / i % 10 == d) res++;
	return res;
}
int x;
int main() {
	cin >> x;
	for (int i = 1; i <= 3; i++)
		if (count(x, i) != i) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
}