#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N =2e5+10; 
int n;
string s;
int buf[4][N<<1];
map<pii,int> Buf;
int cnt[4];
void update(){
	buf[1][cnt[0]-cnt[1]+N]++;
	buf[2][cnt[0]-cnt[2]+N]++;
	buf[3][cnt[1]-cnt[2]+N]++;
	Buf[make_pair(cnt[0]-cnt[1],cnt[0]-cnt[2])]++;
}
int main(){
	cin>>n>>s;
	update();
	long long ans=1ll*n*(n+1)/2;
	for(int i = 0;i<n;i++){
		cnt[s[i]-'A']++;
		ans-=buf[1][cnt[0]-cnt[1]+N];
		ans-=buf[2][cnt[0]-cnt[2]+N];
		ans-=buf[3][cnt[1]-cnt[2]+N];
		ans+=2*Buf[make_pair(cnt[0]-cnt[1],cnt[0]-cnt[2])];
		update();
	}
	cout<<ans;
}