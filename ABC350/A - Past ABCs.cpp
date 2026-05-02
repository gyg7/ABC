#include <bits/stdc++.h>
using namespace std;
char a, b, c;
int num;
int main() {
	cin >> a >> b >> c >> num;
	if ((1 <= num && num <= 315) || (317 <= num && num <= 349))
		printf("Yes");
	else printf("No");
}