#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len;
    int pre, suf, best;
    char leftChar, rightChar;
};

class SegTree {
    int n;
    string s;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pre = a.pre;
        if (a.pre == a.len && a.rightChar == b.leftChar) {
            res.pre = a.len + b.pre;
        }

        res.suf = b.suf;
        if (b.suf == b.len && a.rightChar == b.leftChar) {
            res.suf = b.len + a.suf;
        }

        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suf + b.pre);
        }
        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx].len = 1;
            tree[idx].pre = tree[idx].suf = tree[idx].best = 1;
            tree[idx].leftChar = tree[idx].rightChar = s[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx*2, l, mid);
        build(idx*2+1, mid+1, r);
        tree[idx] = merge(tree[idx*2], tree[idx*2+1]);
    }

    void update(int idx, int l, int r, int pos, char val) {
        if (l == r) {
            s[l] = val;
            tree[idx].leftChar = tree[idx].rightChar = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos, val);
        else update(idx*2+1, mid+1, r, pos, val);
        tree[idx] = merge(tree[idx*2], tree[idx*2+1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(idx*2, l, mid, ql, qr);
        if (ql > mid) return query(idx*2+1, mid+1, r, ql, qr);
        Node left = query(idx*2, l, mid, ql, qr);
        Node right = query(idx*2+1, mid+1, r, ql, qr);
        return merge(left, right);
    }

public:
    SegTree(string str) {
        s = str;
        n = s.size();
        tree.resize(4*n);
        build(1, 0, n-1);
    }

    void update(int pos, char val) {
        update(1, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        Node res = query(1, 0, n-1, l, r);
        return res.best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    SegTree seg(S);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            char x;
            cin >> i >> x;
            seg.update(i-1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l-1, r-1) << "\n";
        }
    }
    return 0;
}