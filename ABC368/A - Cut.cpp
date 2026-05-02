#include <bits/stdc++.h>
using namespace std;
int n, k, a;
queue<int> q;
int main(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        q.push(a);
    }
    for (int i = 1; i <= n - k; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", q.front());
        q.pop();
    }
    return 0;
}