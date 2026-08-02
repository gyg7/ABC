#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, q, x;
set<pair<int, int>> sel;  // 按 l 排序: (l, r)
set<pair<int, int>> ser;  // 按 r 排序: (r, l)

void add(int l, int r) {
    sel.insert({l, r});
    ser.insert({r, l});
}
void del(int l, int r) {
    sel.erase({l, r});
    ser.erase({r, l});
}
int a[500001];

void black(int x) {
    auto itl = sel.lower_bound({x + 1, -inf});
    bool equ0 = (itl != sel.end() && itl->first == x + 1);

    auto itr = ser.lower_bound({x - 1, -inf});
    bool equ1 = (itr != ser.end() && itr->first == x - 1);

    if (equ0 && equ1) {
        int L = itr->second;
        int R = itl->second;
        del(L, itr->first);
        del(itl->first, R);
        add(L, R);
    } else if (equ0) {
        int R = itl->second;
        del(x + 1, R);
        add(x, R);
    } else if (equ1) {
        int L = itr->second;
        del(L, x - 1);
        add(L, x);
    } else {
        add(x, x);
    }
}

// 找到包含 x 的区间，从 x 处断开
void white(int x) {
    // 在 sel 中找：最大的 l ≤ x 的区间
    auto it = sel.upper_bound({x, inf});  // 第一个 l > x 的
    if (it == sel.begin()) return;         // 没有 l ≤ x 的区间
    --it;                                   // 现在 it->first ≤ x
    
    // 检查是否包含 x
    if (it->second < x) return;  // 区间 [l,r] 满足 r < x，不包含 x
    
    int l = it->first;
    int r = it->second;
    
    // 删除原区间
    del(l, r);
    
    // 左边部分 [l, x-1]
    if (l < x) {
        add(l, x - 1);
    }
    // 右边部分 [x+1, r]
    if (x < r) {
        add(x + 1, r);
    }
    // 如果 l == x == r，则两边都不加，x 变成孤立白点
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= q; i++) {
        cin >> x;
        if (a[x] == 0) black(x);
        else white(x);
        a[x] ^= 1;
        cout << sel.size() << '\n';
    }
    return 0;
}