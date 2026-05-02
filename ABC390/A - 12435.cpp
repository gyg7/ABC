#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, a4, a5;
bool cmp() {
	return a1 < a2 && a2 < a3 && a3 < a4 && a4 < a5;
}
void doit(int &x, int &y) {
	swap(x, y);
	if (cmp()) {
		cout << "Yes";
		exit(0);
	}
	swap(x, y);
}
int main() {
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	doit(a1, a2);
	doit(a2, a3);
	doit(a3, a4);
	doit(a4, a5);
	puts("No");
	return 0;
}