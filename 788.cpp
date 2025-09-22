#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;
int n, q[MAXN];

long long merge_sort(int q[], int l, int r)
{
    long long res = 0;
    if (l >= r) return res;

    int mid = l + r >> 1;
    res += merge_sort(q, l, mid);
    res += merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1, tmp[r - l + 1];
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++], res += mid - i + 1;
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k];
    return res;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    cout << merge_sort(q, 0, n - 1) << endl;
}