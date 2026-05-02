#include <bits/stdc++.h>
using namespace std;
int n, x, sum;
vector<string> ve;
string str;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str >> x;
		sum += x;
		ve.push_back(str);
	}
	sort(ve.begin(), ve.end());
	cout << ve[sum % n] << endl;
	return 0;
}