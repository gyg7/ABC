#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        if(i==1||i==n||j==1||j==m)
            cout << "#";
        else
            cout << ".";
    cout<<'\n';}return 0;
}