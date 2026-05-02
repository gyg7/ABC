#include <bits/stdc++.h>
using namespace std;
int cnt;
char ch;
int main() {
	while (scanf("%c", &ch) != EOF) {
		if (ch == '|') {
			cnt ^= 1;
			continue;
		}
		if (cnt == 0)
			putchar(ch);
	}
}