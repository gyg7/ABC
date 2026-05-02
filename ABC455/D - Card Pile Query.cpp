#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int s[N],n,q,sz[N];
int find(int x){
	if(!s[x]) return x;
	return s[x]=find(s[x]);
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		s[x]=y;
	}
	for(int i = 1;i<=n;i++) sz[find(i)]++;
	for(int i=1;i<=n;i++) cout<<sz[i]<<" \n"[i==n];
	return 0;
}