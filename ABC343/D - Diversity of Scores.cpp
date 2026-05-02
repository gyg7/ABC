#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
long long num[200001];
map<long long, int> mp;
int main() {
	cin >> n >> m;
	mp[0] = n;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		mp[num[a]]--;
		if (mp[num[a]] == 0)
			mp.erase(num[a]);
		mp[num[a] += b]++;
		cout << mp.size() << endl;
	}
}