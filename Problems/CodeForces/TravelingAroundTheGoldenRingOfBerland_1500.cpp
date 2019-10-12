#include <iostream>

using namespace std;

int main()
{
    long long N, A;
    cin >> N;
    long long largestTerm = -1;
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A >= largestTerm)
        {
            largestTerm = A;
            index = i;
        }
    }
    cout << (N * (largestTerm - 1)) + (index + 1) << endl;
    return 0;
}
