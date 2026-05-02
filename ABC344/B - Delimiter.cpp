#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<int> ve;
int main() {
	while (scanf("%d", &cnt) != EOF) ve.push_back(cnt);
	reverse(ve.begin(), ve.end());
	for (int v : ve)
		printf("%d ", v);
}