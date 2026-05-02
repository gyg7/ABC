#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> unmap;
char va[2000001], vb[2000001];
void solve() {
	string a, b;
	cin >> a >> b;
	int cnt0 = 0, cnt1 = 0;
	for (char ch : a) {
		if (ch == 'x') cnt0++;
	}
	for (char ch : b)
		if (ch == 'x') cnt1++;
	if (cnt0 != cnt1) {
		puts("No");
		return;
	}
	int topa = 0;
	for (auto ch : a) {
		va[topa++] = ch;
		if (topa >= 4 && va[topa - 4] == '(' && va[topa - 3] == 'x' && va[topa - 2] == 'x' && va[topa - 1] == ')') {
			topa -= 4;
			va[topa++] = 'x';
			va[topa++] = 'x';
		}
	}
	va[topa] = '\0';
	int topb = 0;
	for (auto ch : b) {
		vb[topb++] = ch;
		if (topb >= 4 && vb[topb - 4] == '(' && vb[topb - 3] == 'x' && vb[topb - 2] == 'x' && vb[topb - 1] == ')') {
			topb -= 4;
			vb[topb++] = 'x';
			vb[topb++] = 'x';
		}
	}
	vb[topb] = '\0';
	if (strcmp(va, vb)) {

		puts("No");
	} else puts("Yes");
}
int main() {
	int t;
	for (cin >> t; t; --t)
		solve();
	return 0;
}