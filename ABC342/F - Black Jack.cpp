#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;

// 节点存储的数据：区间和、区间长度
// 虽然只需要单点，但区间和配合长度才能正确计算加法的 lazy 传播
struct S {
	double sum;   // 区间和
	int len;      // 区间长度
};

// 懒标记：表示"区间每个元素加多少"
using F = double;

// 合并两个子节点（用于建树时的 push_up）
S op(S a, S b) {
	return {a.sum + b.sum, a.len + b.len};
}

// 单位元：空区间的和是 0，长度是 0
S e() {
	return {0.0, 0};
}

// 应用懒标记到节点：区间每个元素加 x → 区间和增加 x * len
S mapping(F f, S x) {
	return {x.sum + f * x.len, x.len};
}

// 复合懒标记：先加 g，再加 f → 相当于加 f + g
F composition(F f, F g) {
	return f + g;
}

// 懒标记的单位元：加 0
F id() {
	return 0.0;
}

int main() {
	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// 初始化：每个位置是一个长度为 1 的区间，和为 a[i]
	vector<S> init(n);
	for (int i = 0; i < n; i++) {
		init[i] = {a[i], 1};
	}
	
	// 创建线段树
	lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
	
	// 区间加：给 [l, r) 加上 x
	// 注意：range 是左闭右开区间 [l, r)
	int l = 1, r = 4;  // 示例：给下标 1,2,3 加上 2.5
	double x = 2.5;
	seg.apply(l, r, x);
	
	// 单点查询：获取位置 p 的值
	// 方法：查询区间 [p, p+1) 的和 = 该单点的值
	int p = 2;
	double val = seg.prod(p, p + 1).sum;
	cout << val << endl;
	
	return 0;
}
