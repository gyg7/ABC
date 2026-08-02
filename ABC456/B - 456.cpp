#include <bits/stdc++.h>
using namespace std;
int a[4][7];
void solve(){
	for(int i = 1;i<=3;i++)
		for(int j = 1;j<=6;j++){
			int x;
			cin>>x;
			a[i][x]++;
		}
vector<int> ve({4,5,6});
int res = 0;
	do{
		res += a[1][ve[0]]*a[2][ve[1]]*a[3][ve[2]];
	}while(next_permutation(ve.begin(),ve.end()));
	printf("%.8lf\n",res/216.00);
}
int main(){
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}