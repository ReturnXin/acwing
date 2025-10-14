#include <iostream>
#include <vector>
using namespace std;
vector<int> mul(vector<int>& A, int B)
{
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * B;
        C.push_back(t % 10);
        t = t / 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main(void)
{
    string a;
    int B;
    vector<int> A;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    vector<int> C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
}