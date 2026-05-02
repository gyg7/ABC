#include <bits/stdc++.h>
using namespace std;
int a[6];
int sum[1 << 5], idx[1 << 5];
string str[1 << 5];
int main() {
	for (int i = 1; i <= 5; i++)
		cin >> a[i];
	for (int i = 1; i <= (1 << 5) - 1; i++) {
		for (int j = 1; j <= 5; j++)
			if (i & (1 << (j - 1))) {
				sum[i] += a[j];
				str[i].push_back('A' + j - 1);
			}
		idx[i] = i;
	}
	sort(idx + 1, idx + (1 << 5), [](int i, int j) {
		if (sum[i] != sum[j])
			return sum[i] > sum[j];
		return str[i] < str[j];
	});
	for (int i = 1; i <= (1 << 5) - 1; i++)
		cout << str[idx[i]] << endl;
	return 0;
}