#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;
int a[MAXN], n, k;

void quick_sort(int a[], int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j) {
        do i++;
        while (a[i] < x);
        do j--;
        while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    if (k - 1 > j) {
        quick_sort(a, j + 1, r);
    }
    else {
        quick_sort(a, l, j);
    }
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    cout << a[k - 1] << endl;
}