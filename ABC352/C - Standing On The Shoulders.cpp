#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long a, b;
} p[200001];
bool cmp(node a, node b) {
	return a.a + b.b > a.b + b.a;
}
long long ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].a >> p[i].b;
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= n - 1; i++) 
		ans += p[i].a;
	ans += p[n].b;
	cout << ans << endl;
}