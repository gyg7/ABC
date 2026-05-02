#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, d;
    cin >> m >> d;
    if (m == 1 && d == 7)
        puts("Yes");
    else if (m == 3 && d == 3)
        puts("Yes");
    else if (m == 5 && d == 5)
        puts("Yes");
    else if (m == 7 && d == 7)
        puts("Yes");
    else if (m == 9 && d == 9)
        puts("Yes");
    else
        puts("No");
    return 0;
}