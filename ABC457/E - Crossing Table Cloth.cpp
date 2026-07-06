#include<bits/stdc++.h>
using namespace std;
int n,m,qmr[200002];
vector<int>ml[200001],mr[200001];
int main(){
	cin>>n>>m,qmr[n+1]=1e9;
	for(int i=1,l,r;i<=m;i++)
		cin>>l>>r,ml[l].push_back(r),mr[r].push_back(l);
	for(int i=1;i<=n;i++)
		sort(ml[i].begin(),ml[i].end()),sort(mr[i].begin(),mr[i].end());
	for(int i=n;i;i--)
		if(qmr[i]=qmr[i+1],!ml[i].empty()) qmr[i]=min(qmr[i],ml[i][0]);
	cin>>m;
	while(m--){
		int l,r;cin>>l>>r;
		bool ok=0;
		if(ml[l].empty()||mr[r].empty()){
			cout<<"No\n";
			continue;
		}
		if(binary_search(ml[l].begin(),ml[l].end(),r)){
			int x=upper_bound(ml[l].begin(),ml[l].end(),r)-ml[l].begin();
			if(!(ok=(x>=2))){
				ok=mr[r].end()-lower_bound(mr[r].begin(),mr[r].end(),l)>=2;
				if(!ok) ok=qmr[l+1]<=r;
			}
		}
		int mxl=lower_bound(ml[l].begin(),ml[l].end(),r)-ml[l].begin(),mnr=upper_bound(mr[r].begin(),mr[r].end(),l)-mr[r].begin();
		if(mxl>0&&mnr<mr[r].size()&&ml[l][mxl-1]<r&&mr[r][mnr]>l&&mr[r][mnr]<=ml[l][mxl-1]+1) ok=1;
		cout<<(ok?"Yes\n":"No\n");
	}
	return 0;
}
