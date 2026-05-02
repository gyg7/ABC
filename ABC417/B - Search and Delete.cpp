#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
map<int, int> mp;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		mp[x]++;
	}
for(int i=1;i<=m;i++){
	cin>>x;mp[x]--;
}
for(auto [x,y]:mp)
	for(int j = 1;j<=y;j++) cout<<x<<" ";
	return 0;
}
