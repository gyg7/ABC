#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long arr[3000001],cnt;
void solve(){
string s;
	cin>>s;
	long long ans = 0;
	arr[0]=-1;
	for(int i = 0;s[i+1];i++){
		if(s[i]==s[i+1]){
			arr[++cnt]=i;
		}
	}
	arr[++cnt]=s.size()-1;
	for(int i = 0;i<cnt;++i){
		long long l = arr[i+1]-arr[i];
		ans+=l*(l+1)/2;
		ans%=mod;
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