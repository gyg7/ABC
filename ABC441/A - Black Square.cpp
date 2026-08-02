#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int main() {
	cin >> n >> m >> x >> y;
	if (x < n || n + 100 <= x || y < m || m + 100 <= y) puts("No");
	else puts("Yes");
}