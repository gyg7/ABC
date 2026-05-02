#include <bits/stdc++.h>
using namespace std;
int n, a[101][101][101],q;
int sum(int lx, int rx, int ly, int ry, int lz, int rz) {
	int b[9];
	b[1] = a[rx][ry][rz];
	b[2] = a[lx - 1][ry][rz];
	b[3] = a[rx][ly - 1][rz];
	b[4] = a[rx][ry][lz - 1];
	b[5] = a[lx - 1][ly - 1][rz];
	b[6] = a[lx - 1][ry][lz - 1];
	b[7] = a[rx][ly - 1][lz - 1];
	b[8] = a[lx - 1][ly - 1][lz - 1];
	return b[1] - b[2] - b[3] - b[4] + b[5] + b[6] + b[7] - b[8];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++) {
				int &x = a[i][j][k];
				cin >> x;
				x += a[i - 1][j][k];
				x += a[i][j - 1][k];
				x += a[i][j][k - 1];
				x -= a[i - 1][j - 1][k];
				x -= a[i - 1][j][k - 1];
				x -= a[i][j - 1][k - 1];
				x += a[i - 1][j - 1][k - 1];
			}cin>>q;
			for(int i=1;i<=q;i++){
				int b,c,d,e,f,g;
				cin>>b>>c>>d>>e>>f>>g;
				cout<<sum(b,c,d,e,f,g)<<endl;
			}
}