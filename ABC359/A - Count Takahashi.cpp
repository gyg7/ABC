#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string str;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		if (str == "Takahashi") cnt++;
	}
	printf("%d", cnt);
}