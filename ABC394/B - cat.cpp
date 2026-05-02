#include <bits/stdc++.h>
using namespace std;
int n;
string a[51];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (a[i].size() > a[j].size())
				swap(a[i], a[j]);
		}
	for (int i = 1; i <= n; i++)
		cout << a[i];
	return 0;
}