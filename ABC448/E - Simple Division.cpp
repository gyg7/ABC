#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 10007;
ll k, M, c, l;

ll ksm(ll x, ll y) {
	ll res = 1;
	x %= MOD;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}



struct Trans {
	
	
	vector<vector<short>> to;   
	vector<vector<short>> val;
	vector<short> pow10;        
	void init(int c, ll M) {
		int maxBit = 35; 
		to.resize(maxBit, vector<short>(M));
		val.resize(maxBit, vector<short>(M));
		pow10.resize(maxBit);
		
		for (int r = 0; r < M; r++) {
			ll v = (ll)r * 10 + c;
			to[0][r] = v % M;
			val[0][r] = v / M;  
		}
		pow10[0] = 10 % MOD;
		
		for (int bit = 1; bit < maxBit; bit++) {
			pow10[bit] = (int)((ll)pow10[bit - 1] * pow10[bit - 1] % MOD);
			for (int r = 0; r < M; r++) {
				int mid = to[bit - 1][r];
				to[bit][r] = to[bit - 1][mid];
				
				val[bit][r] = ((ll)val[bit - 1][r] * pow10[bit - 1] + val[bit - 1][mid]) % MOD;
			}
		}
	}
};
Trans trans[10]; 
bool inited[10] = {false};

void apply(int c, ll l, ll &r, ll &ans) {
	if (!inited[c]) {
		trans[c].init(c, M);
		inited[c] = true;
	}
	int bit = 0;
	while (l > 0) {
		if (l & 1) {
			
			ans = (ans * trans[c].pow10[bit] + trans[c].val[bit][r]) % MOD;
			r = trans[c].to[bit][r];
		}
		l >>= 1;
		bit++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> M;
	ll r = 0;      
	ll ans = 0;    
	for (int i = 0; i < k; i++) {
		cin >> c >> l;
		apply((int)c, l, r, ans);
	}
	cout << ans << endl;
	return 0;
}