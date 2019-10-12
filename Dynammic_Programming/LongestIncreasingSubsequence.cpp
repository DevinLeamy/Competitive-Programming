#include <iostream>
#include <vector>

using namespace std;

int getLIS(vector<int> S, int currentI, int currentValue, int length)
{
    if (currentI == S.size())
    {
        return length;
    }
    if (S[currentI] > currentValue)
    {
        return max(getLIS(S, currentI+1, currentValue, length), getLIS(S, currentI+1, S[currentI], length+1));
    } else {
        return getLIS(S, currentI+1, currentValue, length);
    }
}

int main()
{
    int N, E;
    cin >> N;
    vector<int> S;
    for (int i = 0; i < N; i++)
    {
       cin >> E;
       S.push_back(E);
    }
    cout << getLIS(S, 0, -1, 0) << endl;

    return 0;
}
