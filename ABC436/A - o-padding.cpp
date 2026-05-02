#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n - s.length(); i++)
		cout << "o";
	cout << s;
}