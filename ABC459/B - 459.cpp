#include <bits/stdc++.h>
using namespace std;
const int trans[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
int n, x;
string s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		printf("%d", trans[s[0] - 'a']);
	}
}