#include <bits/stdc++.h>
using namespace std;
int x, y, l, r, a, b;
int main() {
	cin >> x >> y >> l >> r >> a >> b;
    int over = max(0,min(r,b)-max(l,a));
	cout << over*x+(b-a-over)*y << endl;
	return 0;
}