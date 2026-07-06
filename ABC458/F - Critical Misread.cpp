#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) { a += b; return a >= MOD ? a - MOD : a; }
int sub(int a, int b) { a -= b; return a < 0 ? a + MOD : a; }
int mul(long long a, long long b) { return (a * b) % MOD; }

// 矩阵类
struct Matrix {
	int n, m;
	vector<vector<int>> a;
	
	Matrix(int n = 0, int m = 0, bool ident = false) : n(n), m(m) {
		a.assign(n, vector<int>(m, 0));
		if (ident) {
			for (int i = 0; i < min(n, m); i++) a[i][i] = 1;
		}
	}
	
	Matrix operator*(const Matrix& o) const {
		Matrix res(n, o.m);
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (a[i][k] == 0) continue;
				for (int j = 0; j < o.m; j++) {
					res.a[i][j] = add(res.a[i][j], mul(a[i][k], o.a[k][j]));
				}
			}
		}
		return res;
	}
};

Matrix power(Matrix base, long long exp) {
	Matrix res(base.n, base.n, true);
	while (exp > 0) {
		if (exp & 1) res = res * base;
		base = base * base;
		exp >>= 1;
	}
	return res;
}

// AC自动机
struct ACAutomaton {
	struct Node {
		int next[26];
		int fail;
		bool bad;
		Node() {
			memset(next, -1, sizeof(next));
			fail = 0;
			bad = false;
		}
	};
	
	vector<Node> nodes;
	
	ACAutomaton() { nodes.emplace_back(); }
	
	void insert(const string& s) {
		int u = 0;
		for (char ch : s) {
			int c = ch - 'a';
			if (nodes[u].next[c] == -1) {
				nodes[u].next[c] = nodes.size();
				nodes.emplace_back();
			}
			u = nodes[u].next[c];
		}
		nodes[u].bad = true;
	}
	
	void build() {
		queue<int> q;
		for (int c = 0; c < 26; c++) {
			if (nodes[0].next[c] != -1) {
				q.push(nodes[0].next[c]);
			} else {
				nodes[0].next[c] = 0;
			}
		}
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (nodes[nodes[u].fail].bad) nodes[u].bad = true;
			
			for (int c = 0; c < 26; c++) {
				if (nodes[u].next[c] != -1) {
					nodes[nodes[u].next[c]].fail = nodes[nodes[u].fail].next[c];
					q.push(nodes[u].next[c]);
				} else {
					nodes[u].next[c] = nodes[nodes[u].fail].next[c];
				}
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long N;
	int K;
	cin >> N >> K;
	
	ACAutomaton ac;
	for (int i = 0; i < K; i++) {
		string s; cin >> s;
		ac.insert(s);
	}
	ac.build();
	
	int M = ac.nodes.size();
	
	// 收集所有非危险状态，建立编号映射（可选，用于缩小矩阵）
	// 如果危险状态不多，也可以直接用全部状态，只是多乘一些0
	vector<int> good;
	vector<int> id(M, -1);
	for (int i = 0; i < M; i++) {
		if (!ac.nodes[i].bad) {
			id[i] = good.size();
			good.push_back(i);
		}
	}
	int G = good.size();
	
	// 构建转移矩阵：G x G
	Matrix T(G, G);
	for (int i = 0; i < G; i++) {
		int u = good[i];
		for (int c = 0; c < 26; c++) {
			int v = ac.nodes[u].next[c];
			if (!ac.nodes[v].bad) {
				T.a[i][id[v]] = add(T.a[i][id[v]], 1);
			}
		}
	}
	
	// 快速幂
	Matrix TN = power(T, N);
	
	// 初始向量：从根节点(状态0)开始
	// 如果根节点是危险的，答案就是0（但通常根不是危险的，除非有空串模式）
	if (ac.nodes[0].bad) {
		cout << 0 << endl;
		return 0;
	}
	
	int ans = 0;
	int start = id[0];
	for (int j = 0; j < G; j++) {
		ans = add(ans, TN.a[start][j]);
	}
	
	cout << ans << endl;
	return 0;
}
