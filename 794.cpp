#include <iostream>
#include <vector>

using namespace std;

vector<int> div(vector<int>& A, int b, int& t)
{
    vector<int> C;
    t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = t * 10 + A[i];
        C.push_back(t / b);
        t = t % b;
    }
    return C;
}

int main(void)
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');
    int t;
    vector<int> C = div(A, b, t);
    int i         = 0;
    while (i < C.size() - 1 && C[i] == 0) i++;
    for (; i < C.size(); i++) cout << C[i];
    cout << endl << t;
}