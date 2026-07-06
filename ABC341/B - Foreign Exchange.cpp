#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
ll n,a[N],s,t;
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i= 1;i<n;i++){
		cin>>s>>t;
		ll num = a[i]/s*t;
		a[i+1]+=num;
	}
	cout<<a[n]<<endl;
}
