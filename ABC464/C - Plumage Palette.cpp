#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N), B(N), D(N);
    for (int i = 0; i < N; i++) cin >> A[i]>>D[i]>>B[i];
    
    // 按 D_i 分组
    vector<vector<int>> birdsAtDay(M + 2);
    for (int i = 0; i < N; i++) {
        birdsAtDay[D[i]].push_back(i);
    }
    
    // cntA[c]: 颜色c在未变色鸟中的数量
    // cntB[c]: 颜色c在已变色鸟中的数量
    // 颜色范围 1..N
    vector<int> cntA(N + 1, 0), cntB(N + 1, 0);
    
    // 初始：所有鸟都未变色（第1天之前的状态，或者说第0天的状态）
    // 但第1天，D_i=1的鸟已经变色了
    // 我们从第1天开始，先假设所有鸟都是未变色，然后处理当天的变色
    
    // 实际上，第j天：D_i <= j 的鸟已变色，D_i > j 的未变色
    // 我们从第1天开始扫描，初始所有鸟未变色，然后每天把 D_i=j 的鸟变色
    
    for (int i = 0; i < N; i++) {
        cntA[A[i]]++;
    }
    
    // 计算初始不同颜色数（所有A_i的不同颜色）
    long long ans = 0;
    for (int c = 1; c <= N; c++) {
        if (cntA[c] > 0) ans++;
    }
    
    vector<long long> res(M + 1);
    
    for (int day = 1; day <= M; day++) {
        // 处理当天变色的鸟
        for (int idx : birdsAtDay[day]) {
            int a = A[idx], b = B[idx];
            
            // 从 cntA 移除 a
            cntA[a]--;
            if (cntA[a] == 0 && cntB[a] == 0) ans--; // a 不再出现
            
            // 加入 cntB 的 b
            if (cntB[b] == 0 && cntA[b] == 0) ans++; // b 开始出现
            cntB[b]++;
        }
        res[day] = ans;
    }
    
    for (int day = 1; day <= M; day++) {
        cout << res[day] << "\n";
    }
    
    return 0;
}