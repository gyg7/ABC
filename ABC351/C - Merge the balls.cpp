#include <bits/stdc++.h>
using namespace std;
int n, x, cnt;
vector <int> ve;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		ve.push_back(x);
		++cnt;
		while (ve.size() >= 2) {
			if (ve[cnt - 1] != ve[cnt - 2]) break;
			int y = ve[cnt - 1] + 1;
			ve.pop_back();
			ve[--cnt - 1] = y;
		}
	}
	printf("%d", cnt);
}