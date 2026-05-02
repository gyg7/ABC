#include <bits/stdc++.h>
using namespace std;
long long num;
int main() {
	cin >> num;
	if (num % 10 == 0) num /= 10;
	else {
		if (num > 0)num = (num + 9) / 10;
		if (num < 0) num = num / 10;
	}
	printf("%lld", num);
}