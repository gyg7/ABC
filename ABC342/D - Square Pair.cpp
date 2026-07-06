#include <bits/stdc++.h>
using namespace std;
int n,a[200010],cnt[200010];
int f(int x){
	int v = 1;
	for(int i=2;i<=x/i;i++){
		if(x%i==0){
			int cnt = 0;
			while(x%i==0){
				++cnt;
				x/=i;
			}
			if(cnt%2) v*=i;
		}
	}
	return v*x;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=f(x);
	}
	long long ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i])
			ans+=cnt[a[i]]+cnt[0];
		else ans+=i-1;
		++cnt[a[i]];
	}
	cout<<ans<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}
