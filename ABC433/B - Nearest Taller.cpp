#include<bits/stdc++.h>
using namespace std;
int n,a[101];
int main(){
    cin>>n;
    for(int i  = 1;i<=n;i++){
        cin>>a[i];
        int ans = -1;
        for(int j=i-1;j>=1;j--) 
        if(a[j]>a[i]){
            ans=j;
            break;
        }
        cout<<ans<<endl;
    }
return 0;
}