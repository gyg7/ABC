#include <bits/stdc++.h>
using namespace std;
int n, k, a;
vector<int> give[110];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a;
			give[a].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << give[i].size() << " ";
		for (int v : give[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}