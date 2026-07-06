#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d;
struct event {
	int ts, op;
} ev[400010];
signed main() {
	cin >> n >> d;
    int tot = 0;
	for (int i = 1; i <= n; i++) {
		int s, t;
		cin >> s >> t; 
        if(s<=t-d){
		ev[++tot] = {s, 1};
        ev[++tot] = {t - d + 1, -1};}
	}
	sort(ev + 1, ev + 1 + tot, [&](event a, event b) {
		return a.ts < b.ts;
	});
	int curr = 0, ans = 0;
	for (int i = 1; i < tot; i++) {
		if (ev[i].op == 1) curr++;
		else curr--;
        int de = ev[i+1].ts-ev[i].ts;
		if (curr >= 2) {
			ans +=  de*(curr - 1) * curr / 2;
		}
	}
	cout << ans << endl;
	return 0;
}