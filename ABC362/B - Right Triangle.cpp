#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
} p[4];
int a[4];
typedef const point & Point;
point operator -(Point a, Point b) {
	return {a.x - b.x, a.y - b.y};
}
int dot(Point a, Point b, Point c) {
	point d = b - a;
	point e = c - a;
	return d.x * e.x + d.y * e.y;
}
int main() {
	for (int i = 1; i <= 3; i++) {
		a[i] = i;
		cin >> p[i].x >> p[i].y;
	}
	do {
		if (dot(p[a[1]], p[a[2]], p[a[3]]) == 0) {
			printf("Yes");
			return 0;
		}
	} while (next_permutation(a + 1, a + 4)) ;
	printf("No");
	return 0;
}
