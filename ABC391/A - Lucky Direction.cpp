#include <bits/stdc++.h>
using namespace std;
string s;
map<string, string> mp = {
	{"N", "S"}, {"S", "N"}, {"E", "W"}, {"W", "E"},
	{"NE", "SW"}, {"NW", "SE"}, {"SW", "NE"}, {"SE", "NW"}
};
int main() {
	cin >> s;
	cout << mp[s] << endl;
	return 0;
}