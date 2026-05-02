#include <bits/stdc++.h>
using namespace std;
int n, a, num, b[101], k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a % k == 0) b[++num] = a / k;
	}
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num - i; j++)
			if (b[j] > b[j + 1])
				swap(b[j], b[j + 1]);
	for (int i = 1; i <= num; i++)
		printf("%d%c", b[i], " \n"[i == num]);
}