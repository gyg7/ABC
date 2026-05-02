#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n, k, id[maxn], a[maxn], ans = maxn, var;
int min_[maxn][25], max_[maxn][25];
bool cmp(int i, int j) {
	return a[i] < a[j];
}
deque<int> que1, que2;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[id[i] = i]);
	sort(id + 1, id + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		while (!que1.empty() && i - que1.front() + 1 > k)
			que1.pop_front();
		while (!que2.empty() && i - que2.front() + 1 > k)
			que2.pop_front();
		while (!que1.empty() && id[que1.back()] >= id[i]) que1.pop_back();
		que1.push_back(i);
		while (!que2.empty() && id[que2.back()] <= id[i]) que2.pop_back();
		que2.push_back(i);
		if (i >= k) {
			int a = que1.front();
			int b = que2.front();
			if ((var = id[b] - id[a]) < ans) ans = var;
		}

	}
	printf("%d", ans);
}