#include <bits/stdc++.h>
using namespace std;
string s;
int sk[200001], top;
char trun(char ch) {
	if (ch == ')') return '(';
	if (ch == ']') return '[';
	if (ch == '>') return '<';
	return 0;
}
int main() {
	cin >> s;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '<')
			sk[++top] = i;
		else if (top == 0) {
			return printf("No"), 0;
		} else if (trun(s[i]) == s[sk[top]]) --top;
		else return printf("No"), 0;
	}
	if (top) printf("No");
	else printf("Yes");
	return 0;
}