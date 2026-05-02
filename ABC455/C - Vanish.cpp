#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> unmap;
typedef long long ll;
int main() {
	int n, k;ll su = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
int x;
		cin>>x;
		unmap[x]++;
        su+=x;
	}
	
	int sz = unmap.size();
	vector<ll> ve;
	for(auto [k,v]:unmap){
	ve.push_back(1ll*k*v);
	}
	sort(ve.begin(),ve.end(),greater<ll>());
	for(int i = 0;i<min(k,sz);i++)
		su-=ve[i];
	cout<<su<<endl;
}
