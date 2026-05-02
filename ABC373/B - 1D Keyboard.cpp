#include <bits/stdc++.h>
using namespace std;
int ns, lst;
char ch[27];
int main() {
	for (int i = 1; i <= 26; i++)
		cin >> ch[i];
	for (int i = 1; i <= 26; i++)
		for (int j = 1; j <= 26; j++)
			if (ch[i] == ch[j] - 1)
				ns += abs(j - i);
	cout << ns << endl;
}