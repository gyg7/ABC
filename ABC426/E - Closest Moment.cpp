#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	double x, y;
	node() {}
	node(double x, double y): x(x), y(y) {}
	double reay() {
		return sqrt(x * x + y * y);
	}
} ts, tg, tv, as, ag, av;
node operator -(node a, node b) {
	return node(a.x - b.x, a.y - b.y);
}

node division(node a, node b, double t) {
	return node(a.x + t * (b-a).x, a.y + t * (b-a).y);
}
double dist(node a, node b) {
	return (a - b).reay();
}
double dist_(node a, node b) {
	auto f = [&](double p) {
		return division(a, b, p).reay();
	};
	double l = 0, r = 1;
	for (int i = 0; i <= 60; i++) {
		double ml = (l + l + r) / 3;
		double mr = (l + r + r) / 3;
		if (f(ml) < f(mr)) r = mr;
		else l = ml;
	}
	return f(l);
}
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	cout<<fixed<<setprecision(15);
}
void clear() {

}

void readmeta() {
	cin >> ts.x >> ts.y >> tg.x >> tg.y;
	cin >> as.x >> as.y >> ag.x >> ag.y;
	tv = ts - tg, av = as - ag;

}
void solve() {
	if (dist(ts, tg) < dist(as, ag)) {
		swap(ts, as);
		swap(tg, ag);
	}
	node tm  = division(ts, tg, dist(as, ag) / dist(ts, tg));
	double d1 = dist_(ts - as, tm - ag);
	double d2 = dist_(tm - ag, tg - ag);
	cout << min(d1, d2) << endl;
}
signed main() {
	pre();
	int t = 1;
	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();

	}
}
