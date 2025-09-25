#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;

int n, q, a[MAXN];

int SL(int l, int r, int x)
{
    while (l < r) {
        int mid = l + r >> 1;   // 向下取整
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int SR(int l, int r, int x)
{
    while (l < r) {
        int mid = l + r + 1 >> 1;   // 向上取整
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

int main(void)
{
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        int k;
        cin >> k;
        int l = SL(0, n - 1, k);
        if (a[l] != k) {
            cout << "-1 -1" << endl;
            continue;
        }
        int r = SR(0, n - 1, k);
        cout << l << " " << r << endl;
    }
    return 0;
}