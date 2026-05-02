#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n, q, x[maxn], p[maxn], a[maxn * 3];
long long s[maxn * 3];
int l[maxn], r[maxn], cnt;
char gc() {
	static char buf[101], *p = buf, *q = buf;
	if (p == q) {
		p = buf;
		q = buf + fread(buf, 1, 100, stdin);
		if (p == q) return -1;
	}
	return *(p++);
}
int read() {
	int x  = 0, f = 1;
	char ch = gc();
	while (isdigit(ch) == 0) {
		if (ch == '-') f = -1;
		ch = gc();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = gc();
	}
	return x * f;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[++cnt] = x[i] = read();
	for (int i = 1; i <= n; i++)
		p[i] = read();
	q = read();
	for (int i = 1; i <= q; i++) {
		a[++cnt] = l[i] = read();
		a[++cnt] = r[i] = read();
	}
	sort(a + 1, a + 1 + cnt);
	int *en = unique(a + 1, a + 1 + cnt);
	for (int i = 1; i <= n; i++)
		x[i] = lower_bound(a + 1, en, x[i]) - a;
	for (int i = 1; i <= q; i++) {
		l[i] = lower_bound(a + 1, en, l[i]) - a;
		r[i] = lower_bound(a + 1, en, r[i]) - a;
	}
	for (int i = 1; i <= n; i++) s[x[i]] += p[i];
	for (int i = 1; i <= cnt; i++) s[i] += s[i - 1];
	for (int i = 1; i <= q; i++) 
		cout << s[r[i]] - s[l[i] - 1] << endl;
}