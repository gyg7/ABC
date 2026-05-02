#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int opt, x, n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> x;
			q.push(x);
		} else {
			cout << q.front() << endl;
			q.pop();
		}}
		return 0;
	}