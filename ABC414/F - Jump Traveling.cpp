#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXK = 20 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN], cnt;
int n,K;

void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int f[MAXN<<1][MAXK],ans[MAXN];
int vis[MAXN][MAXK];

inline void Solve(){
    scanf("%d%d",&n,&K);
    for(int i = 1;i <= n;++i){
        head[i] = 0;
        ans[i] = 1e9;
        for(int j = 0;j <= K;++j) vis[i][j] = 0;
    }
    cnt = 1;
    for(int i = 1;i < n;++i){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i = 1;i <= cnt;++i){
        for(int j = 0;j <= K;++j) f[i][j] = -1;
    }

    queue<pair<int,int> > q;
    for(int i = head[1];i;i=e[i].nxt){
        f[i][1] = 1;
        q.push({i, 1});
    }
    while(!q.empty()){
        auto [id, k] = q.front();q.pop();
        int v = e[id].to, u = e[id^1].to;
        if(k == K) ans[v] = min(ans[v], f[id][k] / K);
        if(vis[v][k] == 2) continue;
        ++vis[v][k];
        for(int i = head[v];i;i = e[i].nxt){
            if(k < K && e[i].to == u) continue;
            int nxt_k = k == K ? 1 : k+1;
            if(f[i][nxt_k] == -1){
                f[i][nxt_k] = f[id][k] + 1;
                q.push({i, nxt_k});
            }
        }
    }
    for(int i = 2;i <= n;++i) printf("%d%c",ans[i]==1e9?-1:ans[i], 
    " \n"[i==n]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}