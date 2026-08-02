#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int sign(double x){
    if(fabs(x)<=eps) return 0;
    return x<0?-1:1;
}
int main() {
	double h, w;
	cin >> h >> w;
    double bmi =w/ (h/100.00) / (h / 100.00); 
	if (sign(bmi-25)>-1) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}