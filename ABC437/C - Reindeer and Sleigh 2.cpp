#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long w, p;
} p[300001];
bool cmp(node a, node b) {
	return a.w + a.p > b.w + b.p;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].w >> p[i].p;
	sort(p + 1, p + 1 + n, cmp);
	long long sp = 0, sw = 0;
	for (int i = 1; i <= n; i++)
		sw += p[i].w;
	for (int i = 1; i <= n; i++) {
		sp += p[i].p;
		sw -= p[i].w;
		if (sp >= sw) {
			cout << n - i << endl;
			return;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}