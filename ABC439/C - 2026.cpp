#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ve;
int num[10000001];
int main() {
	cin >> n;
	for (int x = 1; x * x <= n; x++) {
		for (int y = x + 1; x * x + y * y <= n; y++) {
			num[x * x + y * y]++;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (num[i] == 1) {
			++cnt;
			ve.emplace_back(i);
		}
	cout << cnt << endl;
	for (int v : ve) cout << v << " ";
}