#include <bits/stdc++.h>
using namespace std;
int m, l, sum;
char c;
string s;
int main() {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> c >> l;
		sum += l;
        if(sum>100){
            cout<<"Too Long"<<endl;
            return 0;
        }
		s += string(l, c);
	}
	if (sum <= 100) cout << s;
	else cout << "Too Long" << endl;
	return 0;
}
