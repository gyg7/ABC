#include <iostream>
#include <vector>
using namespace std;

long long permutationRank(const vector<int>& arr) {
    int n = arr.size();
    vector<bool> used(n + 1, false);
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    
    long long rank = 1; 
    
    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (int x = 1; x < arr[i]; x++) {
            if (!used[x]) {
                smaller++;
            }
        }
        rank += smaller * fact[n - i - 1];
        used[arr[i]] = true;
    }
    
    return rank;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }
    
    long long rankP = permutationRank(P);
    long long rankQ = permutationRank(Q);
    long long answer = max(0ll,rankQ - rankP - 1);
    cout << answer << endl;
    
    return 0;
}