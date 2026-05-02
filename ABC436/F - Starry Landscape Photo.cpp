#include<bits/stdc++.h>
using namespace std;
int n,b;
struct BIT{
    int a[500001];
    int lb(int x){
        return x & -x;
    }
    void add(int x,int v){
while(x<=n){
    a[x]+=v;
    x+=lb(x);
}
    }
    int sum(int x){
        int res = 0;
        while(x){
            res+=a[x];
            x-=lb(x);
        }
        return res;
    }
} bit;
int main(){
    cin>>n;
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>b;
        int l = bit.sum(b);
ans+=1ll*(b-l)*(l+1);
bit.add(b,1);
    }
    cout<<ans<<endl;
}