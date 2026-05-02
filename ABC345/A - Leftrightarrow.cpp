#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
	cin >> str;
	if (str[0] != '<') {
		printf("No\n");
		return 0;
	}
	if (str[str.length() - 1] != '>') {
		printf("No\n");
		return 0;
	}
	if (count(str.begin(), str.end(), '<') >= 2) {
		printf("No");
		return 0;
	}
	if (count(str.begin(), str.end(), '>') >= 2) {
		printf("No");
		return 0;
	}
	if (count(str.begin(), str.end(), '=') == 0) {
		printf("No");
		return 0;
	}
	printf("Yes\n");
}