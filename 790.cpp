#include <iostream>
using namespace std;
const double MAXN = 22.0;
double n;
int main(void)
{
    cin >> n;
    double l = -MAXN, r = MAXN;
    while (r - l >= 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid < n)
            l = mid;
        else
            r = mid;
    }
    printf("%.6f", l);
}