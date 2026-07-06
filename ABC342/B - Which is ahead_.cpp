#include <bits/stdc++.h>
using namespace std;
int n,p[110],q,a,b;
void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>p[i];
	}
	cin>>q;
	for(int i = 1;i<=q;i++){
		cin>>a>>b;
		if(p[a]<p[b]) cout<<a<<endl;
		else cout<< b<<endl;
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}
