#include <bits/stdc++.h>
using namespace std;
#define p(a,b) if(a<b) swap(a,b)
int a, b, c, d, e, f, g, h, i, j, k, l;
int main(void) {
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
	p(a, g);p(b, h);p(c, i);p(j, d);p(k, e);p(l, f);
	if (a < d && b < e && c < f) printf("Yes\n");
	else printf("No\n");
	return 0;
}
