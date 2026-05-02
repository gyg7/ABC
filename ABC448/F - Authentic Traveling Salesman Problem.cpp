#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long x, y;
	int id, newId;
} p[60001];
bool cmp1(node a, node b) {
	if (a.x != b.x)return a.x  < b.x;
	return a.y < b.y;
}
int be[60010];
bool cmp2(node a, node b) {
	if (be[a.newId] != be[b.newId])return be[a.newId]  < be[b.newId];
	if (be[a.newId] & 1)
		return a.y < b.y;
	return a.y > b.y;
}
int ans[60010], res[60010];
bool vis[60011];
long long s;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n, cmp1);
	int s = sqrt(n);
	for (int i = 1; i <= n; i++) {
		p[i].newId = i;
		be[i] = (i - 1) / s + 1;
	}
	sort(p + 1, p + n + 1, cmp2);
	for (int i = 1; i <= n; i++)
		if (p[i].id == 1) {
			for (int j = 1; j <= n; j++)
				cout << p[(i + j - 2) % n + 1].id << " ";
			break;
		}
}