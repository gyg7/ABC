#include <bits/stdc++.h>
using namespace std;
int q, a;
bool on;
int sound;
int main() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		if (a == 1) ++sound;
		if (a == 2) sound = max(0, sound - 1);
		if (a == 3) on = !on;
		if (on && sound >= 3) puts("Yes");
		else puts("No");
	}
}