#include <bits/stdc++.h>
using namespace std;
int n, k, x, vis[11];
string S[11];
vector<string > ve;
void dfs(int k, string s) {
	if (!k) {
		ve.push_back(s);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		dfs(k - 1, s + S[i]);
	}
}
int main() {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> S[i];
	dfs(k, "");
	sort(ve.begin(), ve.end());
	cout << ve[x - 1] << endl;
	return 0;
}
