#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw[61], n, pw10[15];
queue<ll> q[61];
ll get() {
	ll res = 0x3f3f3f3f3f3f3f;
	for (int i = 0; i <= 40; i++)
		if (res > q[i].front()) res = q[i].front();
	for (int i = 0; i <= 40; i++) if (res == q[i].front()) q[i].pop();
	return res;
}
int len(int x) {
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}
int main() {
	cin >> n;
	pw10[0] = 1;
	for (int i = 0; i <= 40; i++) {
		pw[i] = (1ll << i);
		q[i].push(pw[i]);
	}
	for (int i = 1; i <= 14; i++) pw10[i] = pw10[i - 1] * 10;
	for (int _ = 1; _ < n; _++) {
		ll x = get();
		for (int i = 0; i <= 40; i++)
			q[i].push(x * pw10[len(pw[i])] + pw[i]);
	}
	cout << get() << endl;
}