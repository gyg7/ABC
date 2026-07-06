#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

struct Point {
	ll x, y;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
	Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
};

ll cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

double slope(const Point &a, const Point &b) {
	return 1.0 * (b.y - a.y) / (b.x - a.x);
}

ll a[N];
int n;
Point stk[N];
int top;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i-1];
	}
	
	// 从右往左构建凸包
	top = 0;
	vector<double> ans(n + 1);
	
	for (int i = n; i >= 0; i--) {  // i = k-1, 从 n 到 0
		Point cur(i, a[i]);
		
		// 维护下凸包
		while (top >= 2 && cross(stk[top-1] - stk[top-2], cur - stk[top-1]) <= 0)
			top--;
		stk[top++] = cur;
		
		if (i < n) {
			// 在凸包上找最大斜率（对当前左端点 i）
			int l = 0, r = top - 1;
			while (l < r) {
				int m = (l + r) / 2;
				// 比较 slope(stk[m], cur) 和 slope(stk[m+1], cur)
				if (slope(stk[m], cur) <= slope(stk[m+1], cur))
					l = m + 1;
				else
					r = m;
			}
			ans[i+1] = slope(stk[l], cur);  // k = i+1
		}
	}
	
	for (int k = 1; k <= n; k++) {
		printf("%.6f\n", ans[k]);
	}
	
	return 0;
}
