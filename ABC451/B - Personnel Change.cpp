#include<bits/stdc++.h>
using namespace std;
int n, m;
int cnt1[101], cnt2[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >>  a >> b;
		cnt1[a]++;
		cnt2[b]++;
	}
	for (int i = 1; i <= m; i++)
		cout << cnt2[i] - cnt1[i] << endl;
}