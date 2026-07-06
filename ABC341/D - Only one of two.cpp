#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll n,ll m){
	return m==0?n:gcd(m,n%m);
}
ll n,m,k,L;
ll cnt(ll x){
	return x/n+x/m-2*(x/L); 
}
int main(){
	cin>>n>>m>>k;
	L = n/gcd(n,m)*m;
	ll l = 0,r = 1e18,ans = 0;
	while(l<=r){
		ll mid = (l+r)/2;
		if(cnt(mid)>=k){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<endl;
}
