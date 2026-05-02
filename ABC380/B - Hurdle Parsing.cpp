#include <bits/stdc++.h>
using namespace std;
char ch;
int cnt;
int main() {
	while (cin >> ch) {
		if (ch == '|') {
			if (cnt) cout << cnt << " ";
			cnt = 0;
		} else cnt++;
	}
}