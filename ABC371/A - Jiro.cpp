#include <bits/stdc++.h>
using namespace std;
char s1, s2, s3;
int main() {
	cin >> s1 >> s2 >> s3;
	if (s1 == '<' && s2 == '<' && s3 == '<')
		printf("B");// a<b a< c b< c
	if (s1 == '<' && s2 == '<' && s3 == '>')
		printf("C");// a<b a<c b > c
	if (s1 == '<' && s2 == '>' && s3 == '>')
		printf("A");// a < b c< a b < c
	if (s1 == '>' && s2 == '<' && s3 == '<')
		printf("A"); // b< a a < c b < c
	if (s1 == '>' && s2 == '>' && s3 == '>')
		printf("B") ;// b < a c < a  c < b
	if (s1 == '>' && s2 == '>' && s3 == '<')
		printf("C") ;// b < a c < a  c < b

	return 0;
}