#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(long long n) {
	string s = to_string(n);
	string rev = s;
	reverse(rev.begin(), rev.end());
	return s == rev;
}
long long largestPalindromeCube(long long N) {
	long long max_x = pow(N, 1.0/3) + 1;
	long long best = 0;
	for (long long x = 1; x <= max_x; x++) {
		long long cube = x * x * x;
		
		if (cube > N) {
			break;
		}
		
		if (isPalindrome(cube)) {
			best = cube;
		}
	}
	
	return best;
}
int main() {
	long long N;
	cin >> N;
	long long result = largestPalindromeCube(N);
	cout << result << endl;	
	return 0;
}
