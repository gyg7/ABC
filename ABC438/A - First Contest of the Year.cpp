#include <bits/stdc++.h>
using namespace std;
int d, f;
int main() {
	cin >> d >> f;
	cout << ((f - d % 7 - 1) % 7 + 7) % 7 + 1 << endl;
}