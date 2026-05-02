#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> pos;
int n, x;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (pos.count(x) == 0)
			pos[x] = -1;
		cout << pos[x] << endl;
		pos[x] = i;
	}
	return 0;
}