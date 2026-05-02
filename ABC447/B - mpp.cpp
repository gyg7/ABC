#include <bits/stdc++.h>
using namespace std;
string s;
int mx, cnt[255];
int main() {
	cin >> s;
	for (char ch : s)
		mx = max(mx, ++cnt[ch]);
	for (char ch : s) 
		if(cnt[ch]!=mx) putchar(ch);
}