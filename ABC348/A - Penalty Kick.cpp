#include <bits/stdc++.h>
using namespace std;
string str = " oox";
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cout << str[(i - 1) % 3 + 1];
}