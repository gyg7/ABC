#include <bits/stdc++.h>
using namespace std;
int a[8], num[14], cnt[2];
int main() {
	for (int i = 1; i <= 7; i++) {
		cin >> a[i];
		num[a[i]]++;
	}
	for (int i = 1; i <= 13; i++) {
		for (int j = 1; j <= 13; j++) {
			if (i != j && num[i] >= 3 && num[j] >= 2) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}