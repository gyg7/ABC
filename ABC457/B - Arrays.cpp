#include <bits/stdc++.h>
using namespace std;
int n,l[200010],a[200010],sum[200010],x,y;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		sum[i]=sum[i-1]+l[i];
		for(int j=1;j<=l[i];j++)
			cin>>a[sum[i-1]+j];
	}
	cout<<a[sum[x-1]+y];
}
