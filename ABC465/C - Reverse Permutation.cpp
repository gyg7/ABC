#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[2 * N], l, r, n;
string s;
bool rev;
int main() {
	cin >> n >> s;
	l = n + 1, r = n;
	for (int i = 0; i < n; i++) {
		if (rev) a[--l] = i + 1;
		else a[++r] = i + 1;
		if (s[i] == 'o') rev ^= 1;
	}
    if(rev) for(int i = l,j=r;i<=j;i++,j--) swap(a[i],a[j]);
	for (int i = l; i <= r; i++) cout << a[i] <<" ";
	return 0;
}