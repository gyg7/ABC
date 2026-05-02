#include <bits/stdc++.h>
using namespace std;
int n, a, cnt[101], num;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (++cnt[a] == 1) num++;
	}
	cout << num << endl;
	for (int i = 1; i <= 100; i++)
		if (cnt[i]) printf("%d\n", i);
	return 0;
}
